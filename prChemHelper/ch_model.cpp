#include <string>
#include <sstream>
#include <stack>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

#include "ch_model.h"
#include "ch_variables_and_types.h"

using namespace std;

string intToStr(int x)
{
    stringstream ss;
    string str;
    ss << x;
    ss >> str;
    return str;
}

int strToInt(string str)
{
    stringstream ss;
    int x;
    ss << str;
    ss >> x;
    return x;
}

string normallize(const string &inputFormula)
{
    string result;
    for (size_t i = 1; i <= inputFormula.size(); i++)
    {
        switch (inputFormula[i])
        {
        case ' ':
            result.push_back('%');
            result.push_back('2');
            result.push_back('0');
            break;
        case '[':
            result.push_back('(');
            break;
        case ']':
            result.push_back(')');
            break;
        default:
            result.push_back(inputFormula[i]);
        }
        // Add case if ((SO4))2;
    }
    return result;
}

// ToDo
/*function CheckForGydrate(var InputFormula: string): Boolean;
var
   i: Integer;
begin
   for i := 1 to Length(InputFormula) do
   begin

   end;
end;*/


bool isNumber(char x)
{
    return (x >= '0' && x <= '9');
}

bool isLetter(char x)
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int getIntegerBeforePosition(const string &str, int &i)
{
    int result = 0;
    int numberStartPosition = 0, numberFinishPosition = 0;
    if(isNumber(str[i]))
    {
        numberFinishPosition = i;
        while ((i >= 0) && isNumber(str[i]))
            i--;
        i++;
        numberStartPosition = i;
        while (i <= numberFinishPosition)
        {
            result *= 10;
            result += str[i] - '0';
            i++;
        }
        i = numberStartPosition - 1;
    }
    if ( result == 0 )
    result++;
    return result;
}


chemElement findElement(const string &someElement)
{
    int i = 0;
    for (size_t i = 0; i < ElementList.size(); i++)
        if (ElementList[i].formula == someElement)
            return ElementList[i];
    return chemElement();
}


chemElement getLatestElement(const string &inputFormula, int &i)
{
    chemElement result;
    int someQuantity = 0;
    someQuantity = getIntegerBeforePosition( inputFormula, i );
    if (i > 0)
        result = findElement(inputFormula.substr(i - 1, 2));
    if (result.formula == "")
        result = findElement(inputFormula.substr(i, 1));
    if (inputFormula[i] == '(' || inputFormula[i] == ')')
    {
        result.formula = inputFormula[i];
        //result.name = stringToWString("");
    }
    if (result.formula == "")
    {
        result.quantity = someQuantity;
        i -= result.formula.size();
    }
    else
        i = -1;
    return result;
}


vector<chemElement> cutToIons(const string inputFormula)
{
    vector<chemElement> result;
    int i = inputFormula.size(), factor = 1;
    chemElement currentElement;
    bool valid = true;
    stack<int> allFactors;
    while ((i>0) && valid)
    {
        currentElement = getLatestElement(inputFormula, i);
        if (currentElement.formula == "")
            valid = false;
        else
        {
            if (currentElement.formula == ")")
            {
                factor *= currentElement.quantity;
                allFactors.push(currentElement.quantity);
            }
            if (currentElement.formula == "(")
            {
                if (!allFactors.empty())
                {
                    factor /= allFactors.top();
                    allFactors.pop();
                }
                else
                    valid = false;
            }
            /*if (currentElement.name != stringToWString(""))
            {
                currentElement.quantity *= factor;
                result.push_back(currentElement);
            }*/
        }
    }
    if (!valid)
        result.clear();
    return result;
}


bool checkOxidationDegreeses(const vector<chemElement> &ionArray, int currentOxidationDegree, size_t currentPosition)
{
    bool result = false;
    if (currentPosition >= ionArray.size())
        return (currentOxidationDegree == 0);
    for (int i = 0; i < 17; i++)
    {
        if (ionArray[currentPosition].degreeOfOxidation[i] != '-')
            result |= checkOxidationDegreeses(ionArray, currentOxidationDegree + (i - 8)*ionArray[currentPosition].quantity, currentPosition + 1);
    }
    return result;
}


bool isValidChemical(const string &someFormula )
{
    int i = 0;
    vector<chemElement> ionArray;
    ionArray = cutToIons(someFormula);
    return  (ionArray.size() >= 1? (ionArray.size() > 1? checkOxidationDegreeses(ionArray, 0, 0) : true) : false);
}

/*function Interpreter(InputFormula: string): string;
var
   InputKation, InputAnion: TIonsArray;
begin
   InputAnion := CutToIons(GetAnionCore, InputFormula);
   InputKation := CutToIons(GetKationCore, InputFormula);
   //GetHtmlPage()
end;*/


string GetHtmlPageGoogleSearch(string request)
{
    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(QNetworkRequest(QUrl(QString::fromStdString("https://www.google.com/search?q=" + request))));
    QEventLoop event;
    QObject::connect(reply, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    return (reply->readAll()).toStdString();
}


/*String __fastcall BackNSymbols( int i, int n, String someStr )
{
  String result;
  int Start = 0, Finish = 0;
  result = "";
  Start = i - n + 1;
  Finish = i;
  if ( Start > 0 )
    for ( int stop = Finish, i = Start; i <= stop; i++)
      result = result + someStr[i];
  return result;
}


String __fastcall ForwardNSymbols( int i, int n, String someStr )
{
  String result;
  int Start = 0, Finish = 0;
  result = "";
  Start = i;
  Finish = i + n - 1;
  if ( Finish <= someStr.Length( ) )
    for ( int stop = Finish, i = Start; i <= stop; i++)
      result = result + someStr[i];
  return result;
}


String __fastcall ShiftUntilX( int& i, Char x, String someStr )
{
  String result;
  result = "";
  while ( ( i <= someStr.Length( ) ) && ( someStr[i] != x ) )
  {
    result = result + someStr[i];
    i++;
  }
  return result;
}


/*void Parse( String HTMLCode )
{
  int i = 0;
  bool DivGOpened = false, H3ROpened = false, AOpened = false, CiteOpened = false;
  int CountDivOpened = 0;
  DynamicArray< String > Titles, URLs;
  DivGOpened = false;
  H3ROpened = false;
  AOpened = false;
  CiteOpened = false;
  i = 1;
  while ( i <= HTMLCode.Length( ) )
  {
      //ShowMessage(IntToStr(i) + BackNSymbols(i, 6, HTMLCode));
    if ( DivGOpened && ( ForwardNSymbols( i, 6, HTMLCode ) == "</div>" ) && ( CountDivOpened == 1 ) )
    {
      DivGOpened = false;
      CountDivOpened--;
    }
    if ( ( CountDivOpened > 0 ) && ( ForwardNSymbols( i, 6, HTMLCode ) == "</div>" ) )
      CountDivOpened--;
    if ( CiteOpened && ( HTMLCode[i] == '<' ) )
    {
      if ( ForwardNSymbols( i, 7, HTMLCode ) == "</cite>" )
        CiteOpened = false;
      else
      {
        ShiftUntilX( i, '>', HTMLCode );
        i++;
      }
    }
    if ( CiteOpened )
    {
      URLs[URLs.Length - 1] = URLs[URLs.Length - 1] + ShiftUntilX( i, '<', HTMLCode );
      i--;
    }
    if ( DivGOpened && ( BackNSymbols( i, 5, HTMLCode ) == "<cite" ) )
    {
      ShiftUntilX( i, '>', HTMLCode );
      CiteOpened = true;
    }
    if ( H3ROpened && ( ForwardNSymbols( i, 5, HTMLCode ) == "</h3>" ) )
      H3ROpened = false;
    if ( AOpened && ( HTMLCode[i] == '<' ) )
    {
      if ( ForwardNSymbols( i, 4, HTMLCode ) == "</a>" )
        AOpened = false;
      else
      {
        ShiftUntilX( i, '>', HTMLCode );
        i++;
      }
    }
    if ( AOpened )
    {
      Titles[Titles.Length - 1] = Titles[Titles.Length - 1] + ShiftUntilX( i, '<', HTMLCode );
      if ( Titles[Titles.Length - 1].Length( ) >= 30 )
      {
        Titles[Titles.Length - 1].SetLength( 30 );
        Titles[Titles.Length - 1] = Titles[Titles.Length - 1] + "...";
        AOpened = false;
      }
      i--;
    }
    if ( H3ROpened && ( BackNSymbols( i, 2, HTMLCode ) == "<a" ) )
    {
      ShiftUntilX( i, '>', HTMLCode );
      AOpened = true;
    }
    if ( DivGOpened && ( BackNSymbols( i, 13, HTMLCode ) == "<h3 class=\"r\"" ) )
    {
      ShiftUntilX( i, '>', HTMLCode );
      H3ROpened = true;
    }
    if ( ( CountDivOpened > 0 ) && ( BackNSymbols( i, 4, HTMLCode ) == "<div" ) )
      CountDivOpened++;
    if ( BackNSymbols( i, 14, HTMLCode ) == "<div class=\"g\"" )
    {
      ShiftUntilX( i, '>', HTMLCode );
      DivGOpened = true;
      CountDivOpened = 1;
      URLs.Length = URLs.Length + 1;
      Titles.Length = Titles.Length + 1;
    }
    i++;
  }
   /*for i := 0 to Length(Titles) - 1 do
   begin
      ShowMessage('x'+Titles[i]+'x');
   end;
   for i := 0 to Length(URLs) - 1 do
   begin
      ShowMessage(Urls[i]);
   end;
  for ( int stop = Min( Titles.Length - 1, 0 ), i = 0; i <= stop; i++)
    /*# with Form1.strngrdSearchResults do
    {
      RowCount = RowCount + 1;
      Cells[0][ RowCount - 1] = Titles[i];
      if ( ForwardNSymbols( 1, 4, URLs[i] ) == "http" )
        Cells[1][ RowCount - 1] = URLs[i];
      else
        Cells[1][ RowCount - 1] = String( "http://" ) + URLs[i];
    }
}*/


/*void fillSGResults( wstring Formula )
{
  wstring PageCode;
  int i = 0;
  for (size_t i = 0; i < CiteArray.size(); i++)
    Parse( GetHtmlPageGoogleSearch( CiteArray[i] + Formula ) );
}

position getObjectPosition(TControl sender)
{
    return position(sender.left, sender.top)
}

double getDistance(position a, position b)
{
    return sqrt(0.0 + (a.left - b.left)*(a.left - b.left) + (a.top - b.top)*(a.top - b.top));
}


bool canAccessInternet( )
{
    bool result = false;
    result = true;
    try
    {
        Form1.IdHTTP1.Get( "http://inetcheck.ucoz.net/index.html" );
        result = true;
    }
    catch(...)
    {
        result = false;
    }
    return result;
}*/

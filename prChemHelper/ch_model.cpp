#include <sstream>
#include <stack>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

#include "ch_model.h"
#include "ch_variables_and_types.h"
#include "ch_graphics.h"

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
    for (size_t i = 0; i < inputFormula.size(); i++)
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
        result.name = "";
    }
    if (result.formula != "")
    {
        result.quantity = someQuantity;
        i -= result.formula.size();
    }
    else
        i = -1;
    return result;
}

vector<chemElement> cutToIons(const string &inputFormula)
{
    vector<chemElement> result;
    int i = inputFormula.size() - 1, factor = 1;
    chemElement currentElement;
    bool valid = true;
    stack<int> allFactors;
    while ((i>=0) && valid)
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
            if (currentElement.name != "")
            {
                currentElement.quantity *= factor;
                result.push_back(currentElement);
            }
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
        if (ionArray[currentPosition].degreeOfOxidation[i] != -1)
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

void launchGEditAnimation()
{
    SYSTEMTIME UTC;
    if (!WasGEditAnimation)
    {
        GetSystemTime(&UTC);
        GEditAnimationRunning = true;
        TimeGEditAnimationStart = sysTimeToInt(UTC);
        WasGEditAnimation = true;
    }
}
void launchGEditInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasGEditAnimation)
    {
        GetSystemTime(&UTC);
        GEditInverseAnimationRunning = true;
        TimeGEditInverseAnimationStart = sysTimeToInt(UTC);
        WasGEditAnimation = false;
        //Form1.FocusControl(NULL);
    }
}

void launchAllAnimation()
{
    SYSTEMTIME UTC;
    if (!WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllAnimationRunning = true;
        TimeAllAnimationStart = sysTimeToInt(UTC);
        WasAllAnimation = true;
    }
}
void launchAllInverseAnimation()
{
    SYSTEMTIME UTC;
    if (WasAllAnimation)
    {
        GetSystemTime(&UTC);
        AllInverseAnimationRunning = true;
        TimeAllInverseAnimationStart = sysTimeToInt(UTC);
        WasAllAnimation = false;
    }
}

void gEditFocusIn(QTextEdit &edtInputFormula)
{
    launchGEditAnimation();
    if(edtInputFormula.toPlainText().toStdString() == "Ваша формула")
        edtInputFormula.setText("");
}
void gEditFocusOut(QTextEdit &edtInputFormula)
{
    launchGEditInverseAnimation();
    if(edtInputFormula.toPlainText().toStdString() == "")
        edtInputFormula.setText("Ваша формула");
}

void gEditAnimationFinished(QGraphicsView &Underscore)
{
    GEditAnimationRunning = false;
    setGEditFinishPosition(Underscore);
}
void gEditInverseAnimationFinished(QGraphicsView &Underscore)
{
    GEditInverseAnimationRunning = false;
    setGEditStartPosition(Underscore);
}

void allAnimationFinished(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults)
{
    AllAnimationRunning = false;
    setAllFinishPosition(GEdit, Logo, SearchResults);
}
void allInverseAnimationFinished(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults)
{
    AllInverseAnimationRunning = false;
    setAllStartPosition(GEdit, Logo, SearchResults);
}

void needRedraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults)
{
    redraw(GEdit, Underscore, Logo, SearchResults);
}

void initializeVariables(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults)
{
    GEdit.move(GEditStartPosition.left, GEditStartPosition.top);
    Logo.move(LogoStartPosition.left, LogoStartPosition.top);
    SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top, SrchResWidth, SrchResStartHeight);
    SearchResults.setColumnWidth(0, 385);
    SearchResults.setColumnWidth(1, 385);
    ElementList = getChemElementArrayFromFile( "data\\files\\Elements.txt" );
    ExceptionList = getStringFromFile( "data\\files\\ExceptionList.txt" );
    PathToBrowser = getStringFromFile( "data\\files\\PathToBrowser.txt" );
    CiteArray = getStringArrayFromFile( "data\\files\\Cites.txt" );
    //string htmlh2o = getStringFromFile("data\\files\\HTMLH2O.txt");
    //string htmlhcl = getStringFromFile("data\\files\\HTMLHCl.txt");
    //string htmlal2so43 = getStringFromFile("data\\files\\HTMLAl2SO43.txt");
    HTMLH2O = getWStringArrayFromFile("data\\files\\HTMLH2O.txt");  //wstring(htmlh2o.begin(), htmlh2o.end());
    HTMLHCl = getWStringArrayFromFile("data\\files\\HTMLHCl.txt");  //wstring(htmlhcl.begin(), htmlhcl.end());
    HTMLAl2SO43 = getWStringArrayFromFile("data\\files\\HTMLAl2SO43.txt");  //wstring(htmlal2so43.begin(), htmlal2so43.end());
}

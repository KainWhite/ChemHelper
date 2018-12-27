#include <fstream>

#include "ch_variables_and_types.h"
#include "chemhelper.h"
#include "ui_chemhelper.h"

using namespace std;

const position GEditStartPosition(277, 271), GEditFinishPosition(100, 50);
const position LogoStartPosition(382, 70), LogoFinishPosition(632, 20);
const position SrchResStartPosition(100, 140);

int MonitorHeight;
int MonitorWidth;
const int EdtInputFormulaWidth = 380, EdtInputFormulaHeight = 50;
const int SrchResWidth = 800, SrchResStartHeight = 0;
int SrchResFinishHeight = 420;
int btnSearchWidth;

bool GEditAnimationRunning = false;
bool GEditInverseAnimationRunning = false;
bool AllAnimationRunning = false;
bool AllInverseAnimationRunning = false;
bool WasGEditAnimation = false;
bool WasAllAnimation = false;
bool WasChangedInputFormula = false;
bool WasJustCreated = true;

vector<chemElement> ElementList;
string ExceptionList;
string PathToBrowser;
vector<string> CiteArray;
std::vector<std::wstring> HTMLH2O;
std::vector<std::wstring> HTMLHCl;
std::vector<std::wstring> HTMLAl2SO43;

int PrevTime = 0;
int TimeGEditAnimationStart = 0;
int TimeGEditInverseAnimationStart = 0;
int TimeAllAnimationStart = 0;
int TimeAllInverseAnimationStart = 0;

const int GEditAnimationTime = 300;
const int AllAnimationTime = 1000;
const double StartAcceleration = 1;
const int StartSpeed = 0;
const double CurrentAccelerationCoefficient = 0.0, CurrentSpeed = 0.0;
const double GEditLeftAcceleration = 4.0 * (GEditFinishPosition.left - GEditStartPosition.left) / sqr(AllAnimationTime),
             GEditTopAcceleration = 4.0 * (GEditFinishPosition.top - GEditStartPosition.top) / sqr(AllAnimationTime);
const double SGAcceleration = 4.0 * (SrchResFinishHeight - SrchResStartHeight) / sqr(AllAnimationTime);
const double GEditUnderscoreAcceleration = 2.0 * EdtInputFormulaWidth / sqr(GEditAnimationTime);
const double LogoLeftAcceleration = 4.0 * (LogoFinishPosition.left - LogoStartPosition.left) / sqr(AllAnimationTime),
             LogoTopAcceleration = 4.0 * (LogoFinishPosition.top - LogoStartPosition.top) / sqr(AllAnimationTime);

const QColor UnderscoreCorrectColor(102, 102, 255);
const QColor UnderscoreWrongColor(255, 20, 20);

// CLASS_METHODS :

// SOME OTHER FUNCTIONS :

void skipSpaces (string someStr, int &i)
{
    while (i <= someStr.size() && someStr[i] == ' ')
        i++;
}

string readUntilSpace(string someLine, int &i)
{
    string Result;
    Result = "";
    while (i <= someLine.size() && someLine[i] != ' ')
    {
        Result = Result + someLine[i];
        i++;
    }
    skipSpaces(someLine, i);
    return Result;
}

vector<chemElement> getChemElementArrayFromFile(string path)
{
    vector<chemElement> result;
    ifstream fin(path.c_str());
    if(!fin.is_open())
        cout<<"Not opened "<<path<<endl;
    string formula, degreeOfOxidation, name;
    while (fin >> formula >> degreeOfOxidation >> name)
    {
        result.push_back(chemElement(formula, degreeOfOxidation, name, 0));
    }
    fin.close();
    return result;
}

vector<string> getStringArrayFromFile(string path)
{
    vector<string> result;
    ifstream fin(path.c_str());
    if(!fin.is_open())
        cout<<"Not opened "<<path<<endl;
    string line;
    while(getline(fin, line))
    {
        result.push_back(line);
    }
    fin.close();
    return result;
}

vector<wstring> getWStringArrayFromFile(string path)
{
    vector<wstring> result;
    wifstream fin(path.c_str());
    if(!fin.is_open())
        cout<<"Not opened "<<path<<endl;
    wstring line;
    while(getline(fin, line))
    {
        result.push_back(line);
    }
    fin.close();
    return result;
}

string getStringFromFile(string path)
{
    string result;
    ifstream fin(path.c_str());
    if(!fin.is_open())
        cout<<"Not opened "<<path<<endl;
    fin >> result;
    fin.close();
    return result;
}

wstring getWStringFromFile(string path)
{
    wstring result;
    wifstream fin(path.c_str());
    if(!fin.is_open())
        cout<<"Not opened "<<path<<endl;
    fin >> result;
    fin.close();
    return result;
}

wstring stringToWString(string str)
{
    return wstring(str.begin(), str.end());
}

int sysTimeToInt(SYSTEMTIME x)
{
    return ((x.wHour * 60 + x.wMinute) * 60 + x.wSecond) * 1000 + x.wMilliseconds;
}

int sqr(int a)
{
    return a * a;
}

bool isKNumber(int code)
{
    return (code >= 48 && code <= 57);
}
bool isKLetter(int code)
{
    return (code >= 65 && code <= 90);
}

std::wstring backNSymbols( int i, int n, const std::wstring &someStr)
{
    std::wstring result(L"");
    int start = i - n + 1, finish = i;
    if (start >= 0)
        for (int i = start; i <= finish; i++)
            result.push_back(someStr[i]);
    return result;
}
std::wstring forwardNSymbols(int i, int n, const std::wstring &someStr)
{
    std::wstring result = L"";
    int start = i, finish = i + n - 1;
    if (finish < someStr.size())
        for (i = start; i <= finish; i++)
            result.push_back(someStr[i]);
    return result;
}
std::wstring shiftUntilX(int& i, char x, const std::wstring &someStr)
{
    std::wstring result = L"";
    while (i < someStr.size() && someStr[i] != x)
    {
        result.push_back(someStr[i]);
        i++;
    }
    return result;
}

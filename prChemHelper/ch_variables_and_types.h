#ifndef CHVARIABLESANDTYPES_H
#define CHVARIABLESANDTYPES_H

#include <string>
#include <vector>
#include <QLabel>
#include <windows.h>
#include <iostream>

class chemElement
{
public:
    std::string formula;
    std::vector<int> degreeOfOxidation;
    std::string name;
    int quantity;
    chemElement () : formula("") {}
    chemElement (const chemElement &x) :
        formula(x.formula), degreeOfOxidation(x.degreeOfOxidation), name(x.name), quantity(x.quantity) {}
    chemElement (std::string _formula, std::string _degreeOfOxidation, std::string _name, int _quantity) :
        formula(_formula), name(_name), quantity(_quantity)
    {
        for(size_t i = 0; i < _degreeOfOxidation.size(); i++)
            degreeOfOxidation.push_back(_degreeOfOxidation[i] == '-'? -1 : _degreeOfOxidation[i] - '0');
    }
};

struct position
{
    int left;
    int top;
    position () {}
    position (const position &x) : left(x.left), top(x.top) {}
    position (const int _left, const int _top) : left(_left), top(_top) {}
};

class QClickableLabel : public QLabel
{
    Q_OBJECT
public:
    QClickableLabel(QWidget *parent = nullptr) : QLabel(parent) {}
    QClickableLabel(QString text, QWidget *parent = nullptr) : QLabel(text, parent) {}
    ~QClickableLabel() {}

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) { emit clicked(); }
};

std::vector<chemElement> getChemElementArrayFromFile(std::string path);
std::vector<std::string> getStringArrayFromFile(std::string path);
std::vector<std::wstring> getWStringArrayFromFile(std::string path);
std::string getStringFromFile(std::string path);
std::wstring getWStringFromFile(std::string path);
std::wstring stringToWString(std::string str);
int sysTimeToInt(SYSTEMTIME x);
int sqr(int a);
bool isKNumber(int code);
bool isKLetter(int code);
std::wstring backNSymbols( int i, int n, const std::wstring &someStr);
std::wstring forwardNSymbols(int i, int n, const std::wstring &someStr);
std::wstring shiftUntilX(int& i, char x, const std::wstring &someStr);

extern const position GEditStartPosition, GEditFinishPosition;
extern const position LogoStartPosition, LogoFinishPosition;
extern const position SrchResStartPosition;

extern int MonitorHeight;
extern int MonitorWidth;
extern const int EdtInputFormulaWidth, EdtInputFormulaHeight;
extern const int SrchResWidth, SrchResStartHeight;
extern int SrchResFinishHeight;
extern int btnSearchWidth;

extern bool GEditAnimationRunning;
extern bool GEditInverseAnimationRunning;
extern bool AllAnimationRunning;
extern bool AllInverseAnimationRunning;
extern bool WasGEditAnimation;
extern bool WasAllAnimation;
extern bool WasChangedInputFormula;
extern bool WasJustCreated;

extern std::vector<chemElement> ElementList;
extern std::string ExceptionList;
extern std::string PathToBrowser;
extern std::vector<std::string> CiteArray;
extern std::vector<std::wstring> HTMLH2O;
extern std::vector<std::wstring> HTMLHCl;
extern std::vector<std::wstring> HTMLAl2SO43;

extern int PrevTime;
extern int TimeGEditAnimationStart;
extern int TimeGEditInverseAnimationStart;
extern int TimeAllAnimationStart;
extern int TimeAllInverseAnimationStart;

extern const int GEditAnimationTime;
extern const int AllAnimationTime;
extern const double StartAcceleration;
extern const int StartSpeed;
extern const double CurrentAccelerationCoefficient, CurrentSpeed;
extern const double GEditLeftAcceleration, GEditTopAcceleration;
extern const double SGAcceleration;
extern const double GEditUnderscoreAcceleration;
extern const double LogoLeftAcceleration, LogoTopAcceleration;

extern const QColor UnderscoreCorrectColor;
extern const QColor UnderscoreWrongColor;

#endif // CHVARIABLESANDTYPES_H

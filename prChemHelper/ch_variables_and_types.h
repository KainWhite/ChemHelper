#ifndef CHVARIABLESANDTYPES_H
#define CHVARIABLESANDTYPES_H

#include <string>
#include <vector>
#include <QLabel>

void initializeVariables( );
std::wstring stringToWString(std::string str);

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
    QClickableLabel() {}
    QClickableLabel(QString text, QWidget *parent = 0) : QLabel(text, parent) {}
    ~QClickableLabel() {}

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) { emit clicked(); }
};

class QShape : public QWidget, public QRect
{
    Q_OBJECT
};

/*class pageHandler : public QObject
{
    Q_OBJECT
public slots:
    void showProgress(qint64 bytesReceived, qint64 bytesTotal);
};*/

extern int PrevTime;
extern int TimeEditAnimationStart;
extern int TimeEditInverseAnimationStart;
extern int TimeAllAnimationStart;
extern int TimeAllInverseAnimationStart;

extern position EditStartPosition, EditFinishPosition;
extern position ImageStartPosition, ImageFinishPosition;
extern position SGBottomStartPosition, SGBottomFinishPosition;

extern bool EditAnimationRunning;
extern bool EditInverseAnimationRunning;
extern bool AllAnimationRunning;
extern bool AllInverseAnimationRunning;
extern bool WasEditAnimation;
extern bool WasAllAnimation;
extern bool WasChangedInputFormula;
extern bool WasJustCreated;

extern std::vector<chemElement> ElementList;
extern std::string ExceptionList;
extern std::string PathToBrowser;
extern std::vector<std::string> CiteArray;

extern const double CurrentAccelerationCoefficient, CurrentSpeed;
extern const double EditLeftAcceleration, EditTopAcceleration;
extern const double SGAcceleration;
extern const double EditLineAcceleration;
extern const double ImageLeftAcceleration, ImageTopAcceleration;
extern const int EditAnimationTime;
extern const int AllAnimationTime;
extern const double StartAcceleration;
extern const int StartSpeed;

extern int MonitorHeight;
extern int MonitorWidth;

extern int HWbtnSearch;

#endif // CHVARIABLESANDTYPES_H

#ifndef CH_MODEL_H
#define CH_MODEL_H

#include <string>
#include <QTextEdit>

bool isValidChemical(const std::string &someFormula );
std::string getHtmlPageGoogleSearch(std::string request);
void gEditFocusIn(QTextEdit &edtInputFormula);
void gEditFocusOut(QTextEdit &edtInputFormula);
void processRequest(const std::string &inputFormula);
void gEditAnimationFinished();
void gEditInverseAnimationFinished();
void allAnimationFinished();
void allInverseAnimationFinished();
void needRedraw();

#endif // A_H

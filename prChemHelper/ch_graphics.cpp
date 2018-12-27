#include <windows.h>

#include "ch_graphics.h"
#include "ch_variables_and_types.h"

void setGEditFinishPosition(QGraphicsView &Underscore)
{
    Underscore.setGeometry(10, EdtInputFormulaHeight + 11, EdtInputFormulaWidth, 4);
}
void setGEditStartPosition(QGraphicsView &Underscore)
{
    Underscore.setGeometry(10, EdtInputFormulaHeight + 10, 0, 4);
}
void setAllFinishPosition(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults)
{
    GEdit.move(GEditFinishPosition.left, GEditFinishPosition.top);
    Logo.move(LogoFinishPosition.left, LogoFinishPosition.top);
    SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top, SrchResWidth, SrchResFinishHeight);
}
void setAllStartPosition(QWidget &GEdit, QLabel &Logo, QTableWidget &SearchResults)
{
    GEdit.move(GEditStartPosition.left, GEditStartPosition.top);
    Logo.move(LogoStartPosition.left, LogoStartPosition.top);
    SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top, SrchResWidth, SrchResStartHeight);
}

void redraw(QWidget &GEdit, QGraphicsView &Underscore, QLabel &Logo, QTableWidget &SearchResults)
{
    SYSTEMTIME UTC;
    int now = 0;
    GetSystemTime(&UTC);
    now = sysTimeToInt(UTC);
    if (GEditAnimationRunning)
    {
        int underscoreWidth;
        if (now - TimeGEditAnimationStart <= GEditAnimationTime / 2)
            underscoreWidth = GEditUnderscoreAcceleration * sqr(now - TimeGEditAnimationStart );
        else
            underscoreWidth = EdtInputFormulaWidth - GEditUnderscoreAcceleration * sqr(TimeGEditAnimationStart + GEditAnimationTime - now);
        Underscore.setGeometry(10 + EdtInputFormulaWidth/2 - underscoreWidth/2, EdtInputFormulaHeight + 11, underscoreWidth, 4);
    }
    if (GEditInverseAnimationRunning)
    {
        int underscoreWidth;
        if (now - TimeGEditInverseAnimationStart < GEditAnimationTime / 2)
            underscoreWidth = EdtInputFormulaWidth - GEditUnderscoreAcceleration * sqr(now - TimeGEditInverseAnimationStart );
        else
            underscoreWidth = GEditUnderscoreAcceleration * sqr(TimeGEditInverseAnimationStart + GEditAnimationTime - now );
        Underscore.setGeometry(10 + EdtInputFormulaWidth/2 - underscoreWidth/2, EdtInputFormulaHeight + 11, underscoreWidth, 4);
    }
    if (AllAnimationRunning)
        if (now - TimeAllAnimationStart <= AllAnimationTime / 2)
        {
            GEdit.move(GEditStartPosition.left + GEditLeftAcceleration * sqr(now - TimeAllAnimationStart) / 2,
                       GEditStartPosition.top + GEditTopAcceleration * sqr(now - TimeAllAnimationStart) / 2);
            Logo.move(LogoStartPosition.left + LogoLeftAcceleration * sqr(now - TimeAllAnimationStart) / 2,
                      LogoStartPosition.top + LogoTopAcceleration * sqr(now - TimeAllAnimationStart) / 2);
            SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top,
                                      SrchResWidth, SGAcceleration * sqr(now - TimeAllAnimationStart) / 2);
        }
        else
        {
            GEdit.move(GEditFinishPosition.left - GEditLeftAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2,
                       GEditFinishPosition.top - GEditTopAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2);
            Logo.move(LogoFinishPosition.left - LogoLeftAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2,
                      LogoFinishPosition.top - LogoTopAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2);
            SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top,
                                      SrchResWidth, SrchResFinishHeight - SGAcceleration * sqr(TimeAllAnimationStart + AllAnimationTime - now) / 2);
        }
    if (AllInverseAnimationRunning)
        if (now - TimeAllInverseAnimationStart <= AllAnimationTime / 2)
        {
            GEdit.move(GEditFinishPosition.left + GEditLeftAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2,
                       GEditFinishPosition.top + GEditTopAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2);
            Logo.move(LogoStartPosition.left + LogoLeftAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2,
                      LogoStartPosition.top + LogoTopAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2);
            SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top,
                                      SrchResWidth, SrchResFinishHeight - SGAcceleration * sqr(now - TimeAllInverseAnimationStart) / 2);
        }
        else
        {
            GEdit.move(GEditFinishPosition.left - GEditLeftAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2,
                       GEditFinishPosition.top - GEditTopAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2);
            //strngrdSearchResults.Height = - SGAcceleration * Sqr( TimeAllInverseAnimationStart + AllAnimationTime - Now ) / 2;
            Logo.move(LogoFinishPosition.left - LogoLeftAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2,
                      LogoFinishPosition.top - LogoTopAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2);
            SearchResults.setGeometry(SrchResStartPosition.left, SrchResStartPosition.top,
                                      SrchResWidth, SGAcceleration * sqr(TimeAllInverseAnimationStart + AllAnimationTime - now) / 2);
        }
}


/*void ShowMessageInvalidInputFormula()
{
  //# with Form1 do
  {
    imgInvalidFormula.Top = edtInputFormula.Top + edtInputFormula.Height + shpLine.Height + 3;
    imgInvalidFormula.Left = edtInputFormula.Left + 30;
    imgInvalidFormula.Visible = true;
  }
}*/

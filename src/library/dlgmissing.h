#pragma once

#include <QItemSelection>

#include "controllers/keyboard/keyboardeventfilter.h"
#include "library/library.h"
#include "library/libraryview.h"
#include "library/ui_dlgmissing.h"
#include "preferences/usersettings.h"

class WLibrary;
class WTrackTableView;
class MissingTableModel;

class DlgMissing : public QWidget, public Ui::DlgMissing, public LibraryView {
    Q_OBJECT

  public:
    DlgMissing(WLibrary* parent, UserSettingsPointer pConfig,
               Library* pLibrary,
               KeyboardEventFilter* pKeyboard);
    ~DlgMissing() override;

    void onShow() override;
    bool hasFocus() const override;
    void setFocus() override;
    void onSearch(const QString& text) override;
    QString currentSearch();
    void saveCurrentViewState() override;
    void restoreCurrentViewState() override;

  public slots:
    void clicked();
    void selectAll();
    void selectionChanged(const QItemSelection&, const QItemSelection&);

  signals:
    void trackSelected(TrackPointer pTrack);

  private:
    void activateButtons(bool enable);
    WTrackTableView* m_pTrackTableView;
    MissingTableModel* m_pMissingTableModel;
};

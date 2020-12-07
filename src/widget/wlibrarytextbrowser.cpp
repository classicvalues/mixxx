// wlibrarytextbrowser.cpp
// Created 10/23/2009 by RJ Ryan (rryan@mit.edu)

#include "widget/wlibrarytextbrowser.h"

#include "moc_wlibrarytextbrowser.cpp"

WLibraryTextBrowser::WLibraryTextBrowser(QWidget* parent)
        : QTextBrowser(parent) {
}

bool WLibraryTextBrowser::hasFocus() const {
    return QWidget::hasFocus();
}

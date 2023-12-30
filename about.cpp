//
// Created by lavandejoey on 09/10/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_about.h" resolved

#include "about.h"
#include "ui_about.h"


about::about(QWidget *parent) :
        QDialog(parent), mUi(new Ui::about) {
    mUi->setupUi(this);
}

about::~about() {
    delete mUi;
}

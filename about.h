//
// Created by lavandejoey on 09/10/23.
//

#ifndef IMAGER_TMP_ABOUT_H
#define IMAGER_TMP_ABOUT_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class about; }
QT_END_NAMESPACE

class about : public QDialog {
Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);

    ~about() override;

private:
    Ui::about *mUi;
};


#endif //IMAGER_TMP_ABOUT_H

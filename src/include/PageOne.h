#pragma once
#include "Session.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>

#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>
#include <Wt/WDoubleSpinBox.h>
#include <Wt/WCheckBox.h>

#include <Wt/WDateEdit.h>
#include <Wt/WTimeEdit.h>

class PageOne : public Wt::WContainerWidget
{
public:

    PageOne(std::shared_ptr<Session> session);

private:

    std::shared_ptr<Session> session_;
    Wt::WTemplate* formTemplate_;

    std::unique_ptr<Wt::WTemplate> create_formWidget();
    std::unique_ptr<Wt::WContainerWidget> create_tableWidget();
    std::unique_ptr<Wt::WComboBox> createComboBox();

    Wt::WLineEdit* stringInput_;
    Wt::WComboBox* selectInput_;
    Wt::WDoubleSpinBox* doubleInput_;
    Wt::WCheckBox* boolInput_;
    // date has two inputs because in the dbo it is stored as a timepoint
    Wt::WDateEdit* dateInput_;
    Wt::WTimeEdit* timeInput_;
    
    std::string dateFormat_ = "dd/MM/yyyy";
    std::string timeFormat_ = "HH:mm";
    std::string dateTimeFormat_ = Wt::WString(dateFormat_ + " " + timeFormat_).toUTF8();

    Wt::WTable* table_;

    void submitBtnClicked();
    void displayData();
};

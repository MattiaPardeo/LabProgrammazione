//
// Created by mattia on 03/09/22.
//

#include "gtest/gtest.h"
#include "../Controller.h"

class ControllerTestSuite : public ::testing::Test{

protected:
    virtual void SetUp(){
        tab = new TabellaModel();
        ctrl = new Controller(tab);
        tab->getTable()->SetValue(1, 1, wxString::Format(wxT("%g"), 3.1));
        tab->getTable()->SetValue(1, 2, wxString::Format(wxT("%g"), 1.0));
        tab->getTable()->SetValue(1, 3, wxString::Format(wxT("%g"), 5.0));
        tab->getTable()->SetValue(2, 1, wxString::Format(wxT("%g"), 1.0));
        tab->getTable()->SetValue(3, 1, wxString::Format(wxT("%g"), 5.0));
    }

    Controller *ctrl;
    TabellaModel *tab;
};

TEST_F(ControllerTestSuite, TestMinRiga){
    ctrl->min(1, 1, 1, 4, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(1, 4));
    ASSERT_DOUBLE_EQ(1, result);
}

TEST_F(ControllerTestSuite, TestMaxRiga){
    ctrl->max(1, 1, 1, 4, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(1, 4));
    ASSERT_DOUBLE_EQ(5, result);
}

TEST_F(ControllerTestSuite, TestMediaRiga){
    ctrl->media(1, 1, 1, 4, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(1, 4));
    ASSERT_DOUBLE_EQ(3.03333, result);
}

TEST_F(ControllerTestSuite, TestSommaRiga){
    ctrl->somma(1, 1, 1, 4, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(1, 4));
    ASSERT_DOUBLE_EQ(9.1, result);
}

TEST_F(ControllerTestSuite, TestMinColonna){
    ctrl->min(1, 4, 1, 1, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(4, 1));
    ASSERT_DOUBLE_EQ(1, result);
}

TEST_F(ControllerTestSuite, TestMaxColonna){
    ctrl->max(1, 4, 1, 1, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(4, 1));
    ASSERT_DOUBLE_EQ(5, result);
}

TEST_F(ControllerTestSuite, TestMediaColonna){
    ctrl->media(1, 4, 1, 1, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(4, 1));
    ASSERT_DOUBLE_EQ(3.03333, result);
}

TEST_F(ControllerTestSuite, TestSommaColonna){
    ctrl->somma(1, 4, 1, 1, tab->getTable());
    double result = wxAtof(tab->getTable()->GetValue(4, 1));
    ASSERT_DOUBLE_EQ(9.1, result);
}
//
// Created by mattia on 02/09/22.
//

#include "gtest/gtest.h"
#include "../TabellaModel.h"

TEST(TabellaModelTest, TestSetTabellaNuova){
    TabellaModel *tabella = new TabellaModel();
    wxGridTableBase *tab = new wxGridStringTable(10, 20);
    tabella->setTable(tab);
    ASSERT_EQ(tab, tabella->getTable());
}
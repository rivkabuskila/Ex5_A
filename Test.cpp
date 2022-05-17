//
// Created by rivka on 13/05/2022.
#include "OrgChart.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
using namespace ariel;

// check add root
TEST_CASE ("add root") {
    OrgChart organization;
    organization.add_root("CEO");
    std::string *s1 = organization.begin();
    CHECK((*s1) == "CEO");
    organization.add_root("CTO");
    std::string *s2 = organization.begin();
    CHECK((*s2) == "CTO");

}
//check add sub
TEST_CASE ("add sub") {
    OrgChart organization;
    organization.add_root("CEO");
    CHECK_THROWS(organization.add_sub("CFO", "CTO"));
    organization.add_sub("CEO", "CTO");
    CHECK(*(organization.begin()) == "CEO");
    CHECK(*(organization.end()) == "CTO");
    CHECK_THROWS(organization.add_sub("AA", "CTO"));
}
//check level order
TEST_CASE ("level order") {
    OrgChart organization;
    organization.add_root("CEO").add_sub("CEO", "CTO");
    CHECK(*(organization.begin_level_order()) == "CEO");
    CHECK(*(organization.end_level_order())  == "CTO");
    organization.add_sub("CEO", "CFO");
    CHECK(*(organization.begin_level_order()) == "CEO");
    CHECK(*(organization.end_level_order())  == "CFO");
    organization.add_sub("CEO", "COO");
    CHECK(*(organization.begin_level_order()) == "CEO");
    CHECK(*(organization.end_level_order()) == "COO");
    organization.add_sub("CTO", "VP_SW");
    CHECK(*(organization.begin_level_order()) == "CEO");
    CHECK(*(organization.end_level_order()) == "VP_SW");
    organization.add_sub("COO", "VP_BI");
    CHECK(*(organization.begin_level_order()) == "CEO");
    CHECK(*(organization.end_level_order())  == "VP_BI");

}
TEST_CASE ("begin level order") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");
    std::string* s = organization.begin_level_order();
    CHECK((*s) == "CEO" );
    }

TEST_CASE ("end level order") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    std::string* s = organization.end_level_order();
            CHECK((*s) == "VP_BI" );
}
//check reverse order
TEST_CASE ("reverse order") {
    OrgChart organization;
    organization.add_root("CEO").add_sub("CEO", "CTO");
    CHECK(*(organization.begin_reverse_order()) == "CTO");
    CHECK(*(organization.end_reverse_order())  == "CEO");
    organization.add_sub("CEO", "CFO");
    CHECK(*(organization.begin_reverse_order()) == "CFO");
    CHECK(*(organization.end_reverse_order())  == "CEO");
    organization.add_sub("CEO", "COO");
    CHECK(*(organization.begin_reverse_order()) == "COO");
    CHECK(*(organization.end_reverse_order()) == "CEO");
    organization.add_sub("CTO", "VP_SW");
    CHECK(*(organization.begin_reverse_order()) == "VP_SW");
    CHECK(*(organization.end_reverse_order()) == "CEO");
    organization.add_sub("COO", "VP_BI");
    CHECK(*(organization.begin_reverse_order()) == "VP_BI");
    CHECK(*(organization.end_reverse_order())  == "CEO");
}
TEST_CASE ("begin reverse order") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    std::string* s = organization.begin_reverse_order();
            CHECK((*s) == "VP_SW" );
}
TEST_CASE ("end reverse order") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    std::string* s = organization.end_reverse_order();
    CHECK((*s) == "CEO" );
}

//check preorder
TEST_CASE ("preorder") {
    OrgChart organization;
    organization.add_root("CEO").add_sub("CEO", "CTO");
    CHECK(*(organization.begin_preorder()) == "CEO");
    CHECK(*(organization.end_preorder())  == "CTO");
    organization.add_sub("CEO", "CFO");
    CHECK(*(organization.begin_preorder()) == "CEO");
    CHECK(*(organization.end_preorder())  == "CFO");
    organization.add_sub("CEO", "COO");
    CHECK(*(organization.begin_preorder()) == "CEO");
    CHECK(*(organization.end_preorder()) == "COO");
    organization.add_sub("CTO", "VP_SW");
    CHECK(*(organization.begin_preorder()) == "CEO");
    CHECK(*(organization.end_preorder()) == "COO");
    organization.add_sub("COO", "VP_BI");
    CHECK(*(organization.begin_preorder()) == "CEO");
    CHECK(*(organization.end_preorder())  == "VP_BI");

}
TEST_CASE ("begin preorder") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    std::string* s = organization.begin_preorder();
            CHECK((*s) == "CEO" );
}
TEST_CASE ("end preorder") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");
    std::string* s = organization.end_preorder();
            CHECK((*s) == "VP_BI" );
}
// check for each
TEST_CASE ("for each") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");
    unsigned long i=0;
    vector<std::string>s ={"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    for (std::string element : organization)
    { // this should work like level order
        CHECK(element == s.at(i));
           i++;
    } // prints: CEO CTO CFO COO VP_SW VP_BI
}

//


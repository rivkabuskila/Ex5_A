//
// Created by rivka on 11/05/2022.
//

#include "OrgChart.hpp"
namespace ariel {
    std::string s1="";
    OrgChart OrgChart::add_root(std::string s) {
        return *this;
    }

    OrgChart OrgChart::add_sub(std::string s1, std::string s2) {
        return *this;
    }

    std::string *OrgChart::begin_level_order() {
        std::string *s = &s1;
        return s;
    }
    std::string *OrgChart::end_level_order() {
        std::string *s = &s1;
        return s;
    }
    OrgChart::level_order_iterator::level_order_iterator(){

    }
    OrgChart::level_order_iterator::level_order_iterator(const level_order_iterator& lo){
    }
    bool OrgChart::level_order_iterator::operator!=(const level_order_iterator& lo) const{
        return true;
    }
    bool OrgChart::level_order_iterator::operator==(const level_order_iterator& lo) const{
        return true;
    }
    OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator++(){
        return *this;
    }
    OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator=(const level_order_iterator& lo) {
        return *this;
    }
    OrgChart::level_order_iterator& operator*(OrgChart::level_order_iterator& lo){
        return lo;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::level_order_iterator& lo){
        return os;
    }
    OrgChart::level_order_iterator::~level_order_iterator(){

    }
    std::string *OrgChart::begin_reverse_order() {
        std::string *s = &s1;
        return s;
       }

    std::string *OrgChart::reverse_order() {
        std::string *s = &s1;
        return s;
    }
    OrgChart::reverse_order_iterator::reverse_order_iterator(){

    }
    bool OrgChart::reverse_order_iterator::operator!=(const reverse_order_iterator& ro) const{
        return true;
    }
    bool OrgChart::reverse_order_iterator::operator==(const reverse_order_iterator& ro) const{
        return true;
    }
    OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator++(){
        return *this;
    }
    OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator=(const OrgChart::reverse_order_iterator& ro){
        return *this;
    }
    OrgChart::reverse_order_iterator& operator*(OrgChart::reverse_order_iterator& ro){
        return ro;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::reverse_order_iterator& ro){
        return os;
    }

    std::string *OrgChart::begin_preorder() {
        std::string *s = &s1;
        return s;

    }

    std::string *OrgChart::end_preorder() {
        std::string *s = &s1;
        return s;
        }

    OrgChart::preorder_iterator::preorder_iterator(){

    }
    bool OrgChart::preorder_iterator::operator !=(const preorder_iterator& p) const{
        return true;
    }
    bool OrgChart::preorder_iterator::operator ==(const preorder_iterator& p) const{
        return true;
    }
    OrgChart::preorder_iterator& OrgChart::preorder_iterator::operator++(){
        return *this;
    }
    OrgChart::preorder_iterator& OrgChart::preorder_iterator::operator=(const preorder_iterator& p){
        return *this;
    }
    OrgChart::preorder_iterator& operator*(OrgChart::preorder_iterator& p){
        return p;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::preorder_iterator& p){
        return os;
    }
    std::string *OrgChart::begin(){
        std::string *s = &s1;
        return s;
    }
    std::string *OrgChart::end(){
        std::string *s = &s1;
        return s;
    }

    std::ostream &operator<<(std::ostream &os, const OrgChart &o) {
        return os;
    }
}
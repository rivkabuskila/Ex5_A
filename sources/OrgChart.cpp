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
    OrgChart::level_order::level_order(){

    }
    OrgChart::level_order::level_order(const level_order& lo){
    }
    bool OrgChart::level_order::operator!=(const level_order& lo) const{
        return true;
    }
    bool OrgChart::level_order::operator==(const level_order& lo) const{
        return true;
    }
    OrgChart::level_order& OrgChart::level_order::operator++(){
        return *this;
    }
    OrgChart::level_order& OrgChart::level_order::operator=(const level_order& lo) {
        return *this;
    }
    OrgChart::level_order& operator*(OrgChart::level_order& lo){
        return lo;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::level_order& lo){
        return os;
    }
    OrgChart::level_order::~level_order(){

    }
    std::string *OrgChart::begin_reverse_order() {
        std::string *s = &s1;
        return s;
       }

    std::string *OrgChart::end_reverse_order() {
        std::string *s = &s1;
        return s;
    }
    OrgChart::reverse_order::reverse_order(){

    }
    bool OrgChart::reverse_order::operator!=(const reverse_order& ro) const{
        return true;
    }
    bool OrgChart::reverse_order::operator==(const reverse_order& ro) const{
        return true;
    }
    OrgChart::reverse_order& OrgChart::reverse_order::operator++(){
        return *this;
    }
    OrgChart::reverse_order& OrgChart::reverse_order::operator=(const OrgChart::reverse_order& ro){
        return *this;
    }
    OrgChart::reverse_order& operator*(OrgChart::reverse_order& ro){
        return ro;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::reverse_order& ro){
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

    OrgChart::preorder::preorder(){

    }
    bool OrgChart::preorder::operator !=(const preorder& p) const{
        return true;
    }
    bool OrgChart::preorder::operator ==(const preorder& p) const{
        return true;
    }
    OrgChart::preorder& OrgChart::preorder::operator++(){
        return *this;
    }
    OrgChart::preorder& OrgChart::preorder::operator=(const preorder& p){
        return *this;
    }
    OrgChart::preorder& operator*(OrgChart::preorder& p){
        return p;
    }
    std::ostream &operator<<(std::ostream &os, const OrgChart::preorder& p){
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
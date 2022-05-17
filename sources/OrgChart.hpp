//
// Created by rivka on 11/05/2022.
//

#ifndef ORGCHART_A_ORGCHART_H
#define ORGCHART_A_ORGCHART_H
#include <string>
#include <vector>
namespace ariel {
    class OrgChart {
    public:
        class level_order_iterator
        {
        private:
            std::string *s;
        public:
            level_order_iterator();
            level_order_iterator(const level_order_iterator& lo);
            bool operator!=(const level_order_iterator& lo) const;
            bool operator==(const level_order_iterator& lo) const;
            level_order_iterator& operator++();
            level_order_iterator& operator=(const level_order_iterator& lo);
            ~level_order_iterator();
            friend level_order_iterator& operator*(OrgChart::level_order_iterator& lo);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::level_order_iterator& lo);
        };

    class reverse_order_iterator
        {
        private:
            std::string *s;
        public:
            reverse_order_iterator();
            reverse_order_iterator(const reverse_order_iterator& ro);
            bool operator !=(const reverse_order_iterator& ro) const;
            bool operator ==(const reverse_order_iterator& ro) const;
           reverse_order_iterator& operator++();
           reverse_order_iterator& operator=(const OrgChart::reverse_order_iterator& ro);
            ~reverse_order_iterator();
            friend reverse_order_iterator& operator*(OrgChart::reverse_order_iterator& ro);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::reverse_order_iterator& ro);
        };
        class preorder_iterator
        {
        private:
            std::string *s;
        public:
            preorder_iterator();
            preorder_iterator(const preorder_iterator& p);
            ~preorder_iterator();
            bool operator!=(const preorder_iterator& p) const;
            bool operator==(const preorder_iterator& p) const;
            preorder_iterator& operator++();
            preorder_iterator& operator=(const OrgChart::preorder_iterator& p);
            friend preorder_iterator& operator*(OrgChart::preorder_iterator& p);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::preorder_iterator& p);
        };

        OrgChart add_root(std::string s);

        OrgChart add_sub(std::string s1, std::string s2);

        std::string *begin_level_order();

        std::string *end_level_order();
        std::string *begin_reverse_order();

        std::string *reverse_order();

        std::string *begin_preorder();

        std::string *end_preorder();
        std::string *begin();
        std::string *end();
        friend std::ostream &operator<<(std::ostream &os, const OrgChart &o);

    };
}

#endif //ORGCHART_A_ORGCHART_H

//
// Created by rivka on 11/05/2022.
//

#ifndef ORGCHART_A_ORGCHART_H
#define ORGCHART_A_ORGCHART_H
#include <string>
#include <vector>
namespace ariel {
    class OrgChart {
    private:
        std::vector<std::vector<std::string>> org;
    public:
        class level_order
        {
        private:
            std::string *s;
        public:
            level_order();
            level_order(const level_order& lo);
            bool operator!=(const level_order& lo) const;
            bool operator==(const level_order& lo) const;
            level_order& operator++();
            level_order& operator=(const level_order& lo);
            ~level_order();
            friend level_order& operator*(OrgChart::level_order& lo);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::level_order& lo);
        };
        class reverse_order
        {
        private:
            std::string *s;
        public:
            reverse_order();
            reverse_order(const reverse_order& ro);
            bool operator !=(const reverse_order& ro) const;
            bool operator ==(const reverse_order& ro) const;
            reverse_order& operator++();
            reverse_order& operator=(const OrgChart::reverse_order& ro);
            ~reverse_order();
            friend reverse_order& operator*(OrgChart::reverse_order& ro);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::reverse_order& ro);
        };
        class preorder
        {
        private:
            std::string *s;
        public:
            preorder();
            preorder(const preorder& p);
            ~preorder();
            bool operator!=(const preorder& p) const;
            bool operator==(const preorder& p) const;
            preorder& operator++();
            preorder& operator=(const OrgChart::preorder& p);
            friend preorder& operator*(OrgChart::preorder& p);
            friend std::ostream &operator<<(std::ostream &os, const OrgChart::preorder& p);
        };

        OrgChart add_root(std::string s);

        OrgChart add_sub(std::string s1, std::string s2);

        std::string *begin_level_order();

        std::string *end_level_order();
        std::string *begin_reverse_order();

        std::string *end_reverse_order();

        std::string *begin_preorder();

        std::string *end_preorder();
        std::string *begin();
        std::string *end();
        friend std::ostream &operator<<(std::ostream &os, const OrgChart &o);

    };
}

#endif //ORGCHART_A_ORGCHART_H

#include<map>
#include<string>
#include<iostream>
#include<vector>
struct Node
{
    std::map<std::string, Node>children; 
};
class Tree
{
    private:
        Node root; 
    public: 
        bool Has(const std::vector<std::string>& node) const;
        void Insert(const std::vector<std::string>& node);
        void Delete(const std::vector<std::string>& node);
};
bool Tree::Has(const std::vector<std::string>& node)
{
    const Node* citem = &root; 
    for(auto item: node) 


}
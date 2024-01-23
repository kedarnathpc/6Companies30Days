
class Tree {
public:
    string name;
    vector<Tree *> children;
    bool isDead;

    Tree() : name(""), isDead(false) {}

    Tree(string _name) : name(_name), isDead(false) {}
};

unordered_map<string, Tree*> mp;

void addChildren(string child, string parent, Tree* root) {
    if (root == NULL) {
        return;
    }

    Tree* parentNode = mp[parent];
    Tree* childNode = new Tree(child);
    parentNode->children.push_back(childNode);
    mp[child] = childNode;
}

void markDeath(string name, Tree* root) {
    if (root == NULL) {
        return;
    }

    Tree* node = mp[name];
    node->isDead = true;
}

void getFamily(Tree* root, vector<string> &ans) {
    if (root == NULL) {
        return;
    }

    if (root->isDead == false) {
        ans.push_back(root->name);
    }

    for (int i = 0; i < root->children.size(); i++) {
        getFamily(root->children[i], ans);
    }
}

class ThroneInheritance {
public:
    Tree* root;

    ThroneInheritance(string kingName) {
        root = new Tree(kingName);
        mp[kingName] = root;
    }

    void birth(string parentName, string childName) {
        addChildren(childName, parentName, root);
    }

    void death(string name) {
        markDeath(name, root);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        getFamily(root, ans);
        return ans;
    }
};
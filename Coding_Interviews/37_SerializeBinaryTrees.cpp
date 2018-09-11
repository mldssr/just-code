// https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include <cstdio>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    char *Serialize(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        string str;

        SerializeCore(root, str);

        int length = str.length();
        char *res = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            res[i] = str[i];
        }
        res[length] = '\0';
        return res;
    }
    void SerializeCore(TreeNode *root, string &str) {
        if (!root) {
            str += '$';
            return;
        }
        str += to_string(root->val);
        str += ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }

    TreeNode *Deserialize(char *str) {
        if (!str) {
            return NULL;
        }
        return DeserializeCore(&str);
    }

    TreeNode *DeserializeCore(char **str) {
        if (**str == '$' || **str == '\0') {    // 无需判断结尾，不会遇到
            ++(*str);
            return NULL;
        }
        int num = 0;
        while (**str != ',') {
            num = 10 * num + (**str - '0');
            ++(*str);
        }
        ++(*str);
        TreeNode *root = new TreeNode(num);
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }
};

void first_order(TreeNode *root) {
    if (!root) return;
    printf("%d ", root->val);
    first_order(root->left);
    first_order(root->right);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution slt;
    char *str = slt.Serialize(root);
    printf("%s\n", str);
    TreeNode *new_root = slt.Deserialize(str);
    first_order(new_root);
    return 0;
}
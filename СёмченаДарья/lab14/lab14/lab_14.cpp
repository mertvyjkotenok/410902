/*������� ����� � ������, ����������� ��� ������� ������, ��������� � ����� �������� �������, � ���������� ��� ������.
����������������� ������ �������� ������� ������ � �������: ����������, �����, �����.
��������� ��������� ������� ������, ��������� � ����� �������� �������.

��������� ������ ������ � ��������� ��������� ����������. 
� �������������� �������� Addr � Father ����� ���� � �������� ���������
� ������� �� ������ ������ ���� ����� ����.
*/
#include <iostream>
#include<Windows.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// �������
TreeNode* insert(TreeNode* root, int val) {
    if (!root)
        return new TreeNode(val);
    if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ����� 
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

// �����
TreeNode* Addr(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->value == val) return root;
    if (val < root->value) return Addr(root->left, val);
    else return Addr(root->right, val);
}

// ����� ����
TreeNode* Father(TreeNode* root, int val, TreeNode* parent = nullptr) {
    if (!root) return nullptr;
    if (root->value == val) return parent;
    if (val < root->value) return Father(root->left, val, root);
    else return Father(root->right, val, root);
}

// ������� � ���������
TreeNode* minValue(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// ��������
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // ��� �������� ��� ����
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // ��� �������
        TreeNode* temp = minValue(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TreeNode* root = nullptr;

    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int val : values)
        root = insert(root, val);

    cout << "�������� ������: ";
    inOrder(root);
    cout << endl;
    int val;
    cout << "���� ���� �� ���������: ";
    cin >> val;

    TreeNode* node = Addr(root, val);
    if (node) {
        TreeNode* parent = Father(root, val);
        if (parent) {
            cout << "���� ������� ���� - ���� �� ���������: " << parent->value << endl;
            root = deleteNode(root, parent->value);
            cout << "���� ���� ������." << endl;
        }
        else {
            cout << "���� � ������, ���� ���." << endl;
        }
    }
    else {
        cout << "���� �� ������!" << endl;
    }

    cout << "������ ����� ��������: ";
    inOrder(root);
    cout << endl;

    return 0;
}
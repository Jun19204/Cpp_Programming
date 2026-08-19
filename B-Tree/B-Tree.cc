#include "B-Tree.h"
#include <vector>


// 소멸자
TreeNode::~TreeNode()
{
    // 하위노드 없는 경우 빠른 리턴
    if (!left && !right) {
        return;
    }

    // 비재귀 후위 순회를 위한 명시적 스택사용(삭제용 스택)
    std::vector<TreeNode*> nodes_to_delete;

    // 하위 노드 삭제용 스택에 넣기
    if (left) {
        nodes_to_delete.push_back(left);
        left = nullptr;
    }
    if (right) {
        nodes_to_delete.push_back(right);
        right = nullptr;
    }

    // 삭제용 스택의 하위노드 삭제
    while (!nodes_to_delete.empty()) {
        TreeNode *current = nodes_to_delete.back();
        nodes_to_delete.pop_back();

        // 자식 노드가 있는 경우
        if (current->left) {
            nodes_to_delete.push_back(current->left);
            current->left = nullptr;
        }
        if (current->right) {
            nodes_to_delete.push_back(current->right);
        }
        
        // 하위 노드 전부 삭제용 스택에 담은 위 현재 노드 해제
        delete current;
    }
}

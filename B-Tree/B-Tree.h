#pragma once

#include <cstddef>
#include <string>

class TreeNode {
public:
    // 생성자
    TreeNode() = default;
    TreeNode(const std::string &s) : value(s) {}
    // 복사 생성자
    TreeNode(const TreeNode&) = delete;
    // 복사 대입 연산자
    TreeNode& operator=(const TreeNode&) = delete;
    // 소멸자
    ~TreeNode();

    // 접근자
    const std::string& get_value() const {
        return value;
    }
    std::size_t get_count() const {
        return count;
    }
    TreeNode* get_left() const {
        return left;
    }
    TreeNode* get_right() const {
        return right;
    }

private:
    std::string value;
    std::size_t count{1};
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
};

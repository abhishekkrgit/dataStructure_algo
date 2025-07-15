# 🌳 Tree DSA - One Page Cheat Sheet

## ✅ Bottom-Up vs Top-Down

- **Bottom-Up**: child → parent  
  ➤ Use when child results determine parent  
  ➤ Eg: Diameter, LCA, Robbery
- **Top-Down**: parent → child  
  ➤ Use when passing info down  
  ➤ Eg: Max Depth, Path Sum, Good Nodes

---

## 🔁 Traversal Types

| Type       | Order    | Used For                   |
|------------|----------|----------------------------|
| Preorder   | Root-L-R | Serialize, Copy            |
| Inorder    | L-Root-R | Validate BST               |
| Postorder  | L-R-Root | Delete, DP, Robbery        |
| LevelOrder | BFS      | Max Width, Zigzag, Connect |

---

## 🌿 Recursion Templates

**Bottom-Up**

```cpp
int dfs(TreeNode* n) {
  if (!n) return 0;
  int l = dfs(n->left), r = dfs(n->right);
  return max(l, r) + 1;
}
```

**Top-Down**

```cpp
int dfs(TreeNode* n) {
  if (!n) return 0;
  int l = dfs(n->left), r = dfs(n->right);
  return max(l, r) + 1;
}
```
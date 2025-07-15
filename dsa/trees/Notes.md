1 # 🌳 Tree DSA Notes (Cheat Sheet)

## ✅ 1. Bottom-Up vs Top-Down Thinking

| Style         | When to Use                                                           | Example Problems                       |
|---------------|-----------------------------------------------------------------------|----------------------------------------|
| **Bottom-Up** | When **child results** determine the parent. Do work after recursion. | Diameter of Tree, LCA, Robbery on Tree |
| **Top-Down**  | When **parent passes info** to children. Track via extra parameters.  | Path Sum, Good Nodes, Max Depth        |

> 🔸 **Rule of Thumb**:  
> If you need to **gather info from children** → use **Bottom-Up**.  
> If you **pass context from parent to children** → use **Top-Down**.

---

## 🔁 2. Traversal Orders

| Order       | Description          | Use Case                                   |
|-------------|----------------------|--------------------------------------------|
| Preorder    | Root → Left → Right  | Copy tree, Serialize                       |
| Inorder     | Left → Root → Right  | Validate BST, Build BST from inorder       |
| Postorder   | Left → Right → Root  | Delete tree, Bottom-up DP                  |
| Level Order | BFS (layer by layer) | Zigzag traversal, Max width, Connect nodes |

---

# advanced-programming-notes
# 進階程式設計專案

本儲存庫包含多個進階程式設計挑戰的實作，包括經典演算法、解謎遊戲以及物聯網專案。

## 目錄
1. [河內塔](#河內塔)
2. [1A2B 數字猜測遊戲](#1a2b-數字猜測遊戲)
3. [迷宮求解](#迷宮求解)
4. [物聯網時鐘](#物聯網時鐘)

---

## 河內塔
**簡介：**
河內塔是一個經典的遞迴問題，包含三根柱子與多個大小不同的圓盤，目標是將所有圓盤從起始柱移動到目標柱，並遵循以下規則：
- 一次只能移動一個圓盤。
- 不能將大圓盤放在小圓盤上。
- 圓盤只能在三根柱子之間移動。

**實作內容：**
- 用遞迴函式解決問題。
- 顯示解決特定數量圓盤所需的步驟。
- 計算總移動步數

---

## 1A2B 數字猜測遊戲
**簡介：**
1A2B是一款數字猜測遊戲，玩法如下：
- 隨機生成一組不重複的 4 位數字。
- 玩家嘗試猜測這組數字。
- 回覆 "A"（數字和位置皆正確）與 "B"（數字正確但位置錯誤）。

**實作內容：**
- 生成不重複的隨機數字。
- 驗證輸入並提供回饋機制。
- 迴圈運行直到玩家猜中正確答案。

---

## 迷宮求解
**簡介：**
透過演算法自動尋找迷宮的解法，從起點到達出口。

**實作內容：**
- 輸入：以二維陣列表示的迷宮。
- 採用不同的搜尋演算法：
  - 深度優先搜尋（DFS）
  - 廣度優先搜尋（BFS）
- 輸出解決方案的路徑。

---

## 物聯網時鐘
**簡介：**
一用ESP32透過網路伺服器獲取時間並顯示在硬體裝置上。

**實作內容：**
- 

---



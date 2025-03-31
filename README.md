# advanced-programming-notes
# 進階程式設計課程紀錄

紀錄多個進階程式設計課程挑戰的實作，包括演算法、解謎遊戲以及物聯網時鐘。

## 目錄
1. 河內塔
2. 1A2B 數字猜測遊戲
3. 迷宮求解
4. 物聯網時鐘https://wokwi.com/projects/425906063096205313

---

## 河內塔——遞迴
**簡介：**
河內塔是一個經典的遞迴問題，包含三根柱子與多個的圓盤，目標是將所有圓盤從開始柱移到目標柱。
- 一次移動一個圓盤。
- 小圓盤在上面
- 圓盤在三根柱子之間移動。

**實作內容：**
- 用遞迴函式解決問題。
- 顯示解決特定數量圓盤所需的步驟。
- 計算總移動步數

---

## 1A2B 數字猜測遊戲——自訂函式
**簡介：**
1A2B是一款數字猜測遊戲，玩法如下：
- 隨機生成一組不重複的 4 位數字。
- 給玩家猜測這組數字。
- 回覆 "A"（數字和位置皆正確）與 "B"（數字正確但位置錯誤）。

**實作內容：**
- 生成不重複的隨機數字（撲克牌演算法）。
- 驗證輸入。
- 迴圈運行直到玩家猜中正確答案。

---

## 迷宮求解——深度優先搜尋（DFS）
**簡介：**
透過DFS演算法自動尋找迷宮的解法，從起點到達出口。

**實作內容：**
- 輸入：以二維陣列表示的迷宮。
- 採用深度優先搜尋（DFS）
- 輸出解決方案的路徑。

---

## 物聯網時鐘——wokwi（https://wokwi.com/projects/425906063096205313）
**簡介：**
一用ESP32透過網路伺服器獲取時間並顯示在硬體裝置上。

**實作內容：**
- 網路截取時間並顯示

---



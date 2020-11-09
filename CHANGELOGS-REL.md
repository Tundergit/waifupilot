dragonpilot 0.7.10.0
========================
* 基於最新 openpilot 0.7.10 devel.
* Based on latest openpilot 0.7.10 devel.
* 修正 Prius 特定情況下無法操控方向盤的問題。
* Fixed unable to regain Prius steering control under certain condition.
* 更新 VW MQB 的支援。(需執行 scripts/vw.sh 腳本)
* Updated support of VW MQB. (scripts/vw.sh script required)
* 新增 2018 China Toyota CHR 指紋v2。（感謝 @xiaohongcheung 提供)
* Added 2018 China Toyota CHR FPv2. (Thanks to @xiaohongcheung)
* 加入 Headunit Reloaded Android Auto App 支援。(感謝 @Ninjaa 提供)
* Added Headunit Reloaded Android Auto App Support. (Thanks to @Ninjaa)
* 優化 nanovg。(感謝 @piggy 提供)
* Optomized nanovg. (Thanks to @piggy)
* 加入 complete_setup.sh (感謝 @深鲸希西 提供)
* Added complete_setup.sh (Thanks to @深鲸希西)
* Based on latest openpilot 0.7.10 devel.
* 修正 EON 接 PC/USB 充電器時仍會自動關機的錯誤。(感謝 @小愛 回報)
* Fixed auto shutdown issue when EON connect to PC/USB Charger. (Thanks to @LOVEChen)
* HYUNDAI_GENESIS 使用 INDI 控制器。(感謝 @donfyffe 提供)
* HYUNDAI_GENESIS uses INDI controller. (Thanks to @donfyffe)
* HYUNDAI_GENESIS 加入 Cruise 按紐 和 lkMode 支援。(感謝 @donfyffe 建議)
* HYUNDAI_GENESIS added Cruise button event and lkMode feature. (Thanks to @donfyffe) 
* 支援台灣版 2018 Huyndai IONIQ + smart MDPS (dp_hkg_smart_mdps) (感謝 @andy741217 提供)
* Support 2018 Taiwan Hyundai IONIQ + smart MDPS (dp_hkg_smart_mdps) (Thanks to @andy741217)
* 使用 openpilot v0.8 的模型。(感謝 @eisenheim)
* Use openpilot v0.8 model. (Thanks to @eisenheim)
* 加入 0.8 測試版的部分優化。
* Added optimizations from pre-0.8.
* 加入 dp_honda_eps_mod 設定來使用更高的扭力 (需 eps mod)。(感謝 @Wuxl_369 提供)
* Added dp_honda_eps_mod setting to enable higher torque (eps mod required). (Thanks to @Wuxl_369)
* 修正 VW 對白/灰熊的支援 (感謝 @lirudy 提供)
* Fixed issue with white/grey panda support for VW (Thanks to @lirudy)
* GENESIS_G70 優化 (感謝 @sebastian4k 提供)
* GENESIS_G70 Optimisation (Thanks to @sebastian4k)
* HYUNDAI_GENESIS 優化 (感謝 @donfyffe 提供)
* HYUNDAI_GENESIS Optimisation (Thanks to @donfyffe)

dragonpilot 0.7.8
========================
* 基於最新 openpilot 0.7.8 devel.
* Based on latest openpilot 0.7.8 devel.
* 加入重置 DP 設定按鈕。(感謝 @LOVEChen 建議)
* Added "Reset DP Settings" button. (Thanks to @LOVEChen)
* 將警示訊息更改為類似於概念 UI 的設計。
* Alert messages changed to concept UI alike design.
* 當 manager 出現錯誤後，按 Exit 按鈕會執行 reset_update 腳本。
* Added ability to execute reset_update.sh when press "Exit" button once manager returned errors. 
* 加入 ko-KR 翻譯。
* Added ko-KR translation.
* 加入 Honda Jade 支援。(感謝 @李俊灝)
* Added Honda Jade support. (Thanks to @lijunhao731)
* 修正 ui.cc 內存越界的問題。(感謝 @piggy 提供)
* Fixed ui.cc memory out of bound issue. (Thanks to @piggy)
* gpxd 記錄改自動存成 zip 格式。
* gpxd now store in zip format.
* 強制關閉 panda 檢查 DOS 硬體。
* Force disabled DOS hardware check in panda.
* 修正在沒網路的情況下，開機超過五分鐘的問題。
* Fixed 5+ minutes boot time issue when there is no internet connection.
* 錯誤回傳改使用 dp 的主機。
* Used dp server for error reporting.
* 更新服務改使用 gitee 的 IP 檢查連線狀態。
* updated service uses gitee IP address instead.
* VW 加入 6 分鐘時間方向盤控制限制輔助方案。(特別感謝 @actuallylemoncurd 提供代碼)
* VW added 6 minutes timebomb assist. (dp_timebomb_assist, special thanks to @actuallylemoncurd)

dragonpilot 0.7.7.0
========================
* 基於最新 openpilot 0.7.7 devel.
* Based on latest openpilot 0.7.7 devel.
* 當 Manager 出現錯誤時，顯示 IP 位置。(感謝 @dingliangxue)
* When Manager failed, display IP address. (Thanks to  @dingliangxue)
* 加回 sr learner 開關。
* Re-added sr learner toggle.

dragonpilot 0.7.6
========================
* 基於最新 openpilot 0.7.6.1 devel.
* Based on latest openpilot 0.7.6.1 devel.
* 優化並整合 dp 服務。 (所有的設定檔已改名，請重新設定所有的功能)
* Optimized and integrated several dp services. (Settings have been renamed, please re-config all settings)
* 完全關閉 steer ratio learner。
* Completely disabled steer ratio learner.
* 移除「加速模式」。
* Removed Accel Profile.
* 加入本田皓影混電版指紋v1。(感謝 @劉駿)
* Added Honda Breeze Hybrid FPv1. (Thanks to @劉駿)
* 加入台灣版 Toyota Prius 4.5 指紋v1。(感謝 @jeekid)
* Added Taiwan Toyota Prius 4.5 FPv1. (Thanks to @jeekid)
* 加入 2020 Toyota Prius 指紋v2。(感謝 @Trae)
* Added Toyota Prius 2020 FPv2. (Thanks to @Trae)
* 優化 Honda CR-V Hybrid 轉向。(感謝 @martint1980)
× Optomised Honda CR-V Hybrid lateral control. (Thanks to @martint1980) 

dragonpilot 0.7.5
========================
* 優化 Lexus GSH 轉向。(感謝 @簡銘佑 測試)
* Optimize Lexus GSH steering. (Thanks to @簡銘佑)
* C2 支援自動關機「DragonAutoShutdownAt」參數。(感謝 @cgw1968 建議)
* C2 to support auto shutdown "DragonAutoShutDownAt" param. (Thanks to @cgw1968)
* 將剎車狀熊顯示於 dp 資訊欄。
* Added brake indicator to dp infobar.
* 加入「方向燈取消控制」延遲控制設。(感謝 @wabes 建議)
* Added delay config to "Disable Lat Control on Blinker". (Thanks to @wabes)
* 加入巴西版 2020 Corolla Hybrid 指紋v2。(感謝 @berno22 提供)
* Added Brazil 2020 Corolla Hybrid FPv2. (Thanks to @berno22) 
* 加入對 VW MQB/PQ 的支援。(感謝 @dingliangxue 移植)
* Added support to VW MQB/PQ platform. (Thanks to @dingliangxue)
* 加入「允許多次自動換道」功能。(感謝 @阿濤 建議)
* Added "Allow Continuous Auto Lane Change" Toggle. (Thanks to @阿濤)
* 新增 DragonMaxSpeedLimit 設定值 (mph)，當如果車速高於此值 op 將會停止操控。(感謝 @Anthony 建議)
* Added DragonMaxSpeedLimit parameter (mph), op will stop controlling when car speed is high than the value. (Thanks to @Anthony)
* 新增加拿大版 2018 Toyota Sienna LTD 指紋(v2)。(感謝 明峰 提供)
* Added Canada 2018 Toyota Sienna LTD fingerprint (v2). (Thanks to 明峰)
* 新增「通過移動網路上傳」開關
* Added Upload Over Mobile Network toggle.
* 新增「通過熱點上傳」開關
* Added Upload Over Hotspot toggle.
* 新增加拿大版 2018 Toyota Sienna LTD 指紋(v1)。(感謝 明峰 提供)
* Added Canada 2018 Toyota Sienna LTD fingerprint (v1). (Thanks to 明峰)
* 新增大陸版 Volkswagen Golf GTI 指紋 (v1)。(感謝 easyeiji 提供)
* Added China Volkswagen Golf GTI fingerprint (v1). (Thanks to easyeiji)
* 更新 dp 圖示 (特別感謝 @wabes 的設計與提供)。
* Updated dp logo, special thanks to @wabes for the design.
* 簡/繁中文版和 i18n 整合成為單一版本。  
* Merged zhs/zht/i18n versions into one.
* 新增大陸版 CAMRY HYBRID 指紋v2。(感謝 @杜子腾)
* Added China Camery Hybrid FPv2. (Thanks to @杜子腾) 
* 新增台灣版 Altis HYBRID 指紋v1。(感謝 @Fish)
* Added Taiwan Altis Hybrid FPv1. (Thanks to @Fish)
* 新增行駛時關閉畫面功能。
* Added Screen off while driving feature.
* 新增倒車時關閉畫面功能。
* Added Screen off while reversing feature.
* 新增駕駛介面加入「加速模式」切換鈕。 
* Added acceleration profile toggle onto driving UI.
* 新增自定車型功能，取代指紋暫存功能。
* Replaced fingerprint cache with custom car model selector.
* 新增可調亮度。
* Added Brightness changer.
* 新增部分德語支持。(特別感謝 @arne182 提供)
* Added partial de_DE language support (Thanks to @arne182)

dragonpilot 0.7.4
========================
* [2020-04-10] 移除所有的第三方應用改為自動下載。
* [2020-04-10] 移除「啟用原廠 DSU 模式」、「安全帶檢查」、「車門檢查」開關。
* [2020-03-31] 還原部分修改代碼以達到 comma ai 安全準則。 (Reverted changes to panda safety code to comply with comma ai safety guideline.)
* [2020-03-31] 調整「啟用原廠 DSU 模式」為踩剎車時會暫時斷開控制 。(Enable Stock DSU Mode will temporary disable controls when brake is pressed.)
* [2020-03-27] 加入波蘭版 2015 Lexus NX200T 支援。(感謝 wabes 提供)
* [2020-03-27] 調整「啟用原廠 DSU 模式」為不再需要 AHB 。(Enable Stock DSU Mode no longer requires "AHB" toggle)
* [2020-03-27] 加入「安全帶檢查」、「車門檢查」、「檔位檢查」、「溫度檢查」開關。
* [2020-03-27] 加入曲率學習功能 - Curvature Learner 。(感謝 zorrobyte 提供)
* [2020-03-27] 加入大陸版 2018 Toyota Highlander 支援。(感謝 toyboxZ 提供)
* [2020-03-27] 加入大陸版 2018 Toyota Camry 2.0 支援。(感謝 Rming 提供)
* [2020-03-27] 加入韓文支持。(感謝 crwusiz 提供)
* [2020-03-27] 調整 OFFROAD 主頁翻譯將 "dragonpilot" 改回 "openpilot"。

dragonpilot 0.7.3
========================
* [2020-03-17] 加入動態調整車距功能。(特別感謝 @ShaneSmiskol 提供 PR)
* [2020-03-14] 更新 pt-Br (葡萄牙語) 翻譯。(感謝 berno22 提供)
* [2020-03-14] 加入自動關機開關。(感謝 Rzxd 建議)
* [2020-03-14] 調高 Toyota 扭力容錯值。
* [2020-03-14] 優化讀取 dp 設定值。
* [2020-03-14] 加入 2019 手動 Civic 指紋。感謝 (AlexNoop 提供)
* [2020-03-14] dp 功能加入對 Subaru 車系的支援。
* [2020-03-06] 加入葡萄牙語支持。(感謝 berno22 提供)
* [2020-03-06] 加入大陸 2018 Camry、2020 RAV4 指紋。(感謝 笨木匠 提供)
* [2020-03-04] 加入顯示駕駛監控畫面。
* [2020-03-04] 加入加速模式選項。(特別感謝 @arne182, @cgw1968-5779 提供 PR)
* [2020-03-04] 修正 shutdownd 在 comma two 可能會不正常關機的錯誤。(感謝 @Wei, @Rzxd 回報)

dragonpilot 0.7.2
========================
* [2020-02-08] dp 功能加入對現代 (Hyundai) 車系的支援。
* [2020-02-08] 加入神盾測速照相自動啟動的開關。
* [2020-02-08] 更新高德地圖至 v4.5.0.600053。
* [2020-02-08] 使用 0.6.6 版的更新系統。
* [2020-02-08] 修正急剎問題。(感謝 kumar 提供)
* [2020-01-31] 移除行車介面電量、溫度顯示，(修正畫面當機、黑屏問題)
* [2020-01-29] 修正行車介面錯誤。(感謝 深鲸希西 測試；eisenheim、HeatNation 反應)
* [2020-01-23] 加入 Steer Ratio Learner 關閉。(感謝 eisenheim 建議)
* [2020-01-23] 行車介面加入電量、溫度。(感謝 eisenheim 建議)
* [2020-01-23] 優化 appd。

dragonpilot 0.7.1
========================
* [2020-01-19] 調整 appd 和 ALC 邏輯。 
* [2020-01-14] 加入開機啟動個人熱點。(感謝 eisenheim 建議)
* [2020-01-18] 加入大陸版 2018 Lexus RX300 支援。(感謝 cafe 提供)
* [2020-01-18] 加入 DragonBTG 設定。(感謝 CloudJ、低調哥、歐姓Altis車主 提供)

dragonpilot 0.7.0
========================
* [DEVEL] 更新至最新的 commaai:devel (0.7.0)。
* [2019-12-29] 輔助/自動變道改為可調整參數 (進階用戶)。(DragonAssistedLCMinMPH、DragonAutoLCMinMPH、DragonAutoLCDelay)
* [2019-12-29] 修正無法運行第三方應用錯誤。(感謝 深鲸希西 反應)
* [2019-12-18] 修正自動換道邏輯。
* [2019-12-18] 更新 offroad 翻譯。
* [2019-12-18] 錯誤修正。
* [2019-12-18] 移除美版 2017 Civic Hatchback 指紋。(與其它車型衝突)
* [2019-12-17] 加入輔助換道開關。（24mph / 40kph 以上)
* [2019-12-17] 加入自動換道開關。（40mph / 65kph 以上)
* [2019-12-17] 加入大陸版 2019 雷凌汽油版指紋。 (感謝 Shell 提供)
* [2019-12-17] 加入大陸版 2019 卡羅拉汽油版指紋。 (感謝 Shell 提供)
* [2019-12-17] 加入美版 2017 Civic Hatchback 指紋。(感謝 CFranHonda 提供)
* [2019-12-10] 加入位智車機模式。 (Waze Mode)
* [2019-11-21] 修正 offroad 翻譯。(感謝 鄧育林 回報)
* [2019-11-21] 調整前車靜止移動偵測參數。
* [2019-11-21] 前車靜止移動偵測可在未啟用 dp 時運作。
* [2019-11-18] 修正 offroad 翻譯。(感謝 Cody、鄧育林 回報)
* [2019-11-18] 修正 frame 翻譯。

dragonpilot 0.6.6
========================
* [2019-11-15] 修正不會充電的錯誤。 (感謝 袁昊 反應)
* [2019-11-15] 修正充電控制。 (感謝 KT 反應)
* [2019-11-15] 更新 frame 翻譯，改為多語言版。 (感謝 深鲸希西、shaoching885、鄧育林 反應)
* [2019-11-12] 只顯示電量文字 (注意：有時不會更新，需要拔插 USB 線)
* [2019-11-12] 自動偵測並鎖定硬體 (EON / UNO)。
* [2019-11-12] 加入鎖定硬體 (EON / UNO) 的程式碼。
* [2019-11-11] 更新高德地圖至 v4.3.0.600310 R2098NSLAE
* [2019-11-11] 更新 MiXplorer 至 v6.40.3
* [2019-11-11] 前車靜止移動偵測加入偵測警示。
* [2019-11-07] 讓 Bosch 系統顯示三角。 (感謝 ching885 回報)
* [2019-11-07] 更新 offroad 多語言版簡體中文翻譯 (感謝 Rming 提供)
* [2019-11-06] 修正 0.6.6 appd 和 dashcamd 錯誤。 (感謝 鄧育林 回報)

dragonpilot 0.6.5
========================
* [2019-11-05] 加入台灣 Lexus 2017 GS450h 支援。 (感謝 簡銘佑 提供指紋)
* [2019-11-01] 新增神盾測速照相。 (感謝 Sky Chang 和 Wei Yi Chen)
* [2019-11-01] 修正 offroad 翻譯。 (感謝 Leo Hsieh)
* [2019-11-01] 移除 Miui 字型，縮小 dp 使用空間。
* [2019-11-01] 更新 offroad 為多語言版
* [2019-10-29] 加入 SnG 補丁。（感謝 楊雅智)
* [2019-10-28] 調整 dragon_allow_gas 邏輯 (請回報任何問題，需更新 Panda 韌體)
* [2019-10-22] 移除強迫網路連線提示。(感謝 Shell)
* [2019-10-18] 加入前車靜止移動偵測。(測試版，感謝 ucolchen)
* [2019-10-18] 移除強迫網路連線提示。(感謝 Shell)
* [2019-10-18] 修正 allow_gas 功能。
* [2019-10-18] 加入彎道減速功能開關。
* [2019-10-18] 強迫使用 dp 版 Panda 韌體。
* [2019-10-17] 加入「車型」顯示於 dp 設定畫面。
* [2019-10-17] 修正充電控制讀取預設值的錯誤。
* [2019-10-17] 修正無法顯示更新記錄的錯誤。
* [2019-10-17] 刷新 Panda 韌體按鈕將會自動重啟 EON。(感謝 鄧育林 建議)
* [2019-10-17] 下載更新記錄時使用 "no-cache" 標頭。
* [2019-10-17] 更新高德地圖至 v4.3.0
* [2019-10-14] 啟用自動更新功能。(感謝 鄧育林 提供)
* [2019-10-14] 清除不再使用的 dp params。
* [2019-10-14] 加入數字電量指示。(感謝 鄧育林 建議)
* [2019-10-14] 加入刷新 Panda 韌體按鈕。
* [2019-10-11] 加入台灣 2019 RAV4 汽油版指紋。 (感謝 Max Duan / CloudJ 提供)
* [2019-10-11] 加入當 LatCtrl 關閉時，畫面顯示提示訊息。

dragonpilot 0.6.4
========================
* [2019-10-11] 加入台灣版 2019 RAV4H 油電版指紋。
* [2019-10-08] 加回駕駛監控開關。
* [2019-10-07] 加入台灣版 2019 RAV4H 油電版指紋。(感謝 Max Duan 提供)
* [2019-10-05] 移除 curvature learner: 轉角明顯比原廠小。
* [2019-09-30] 更新 curvature learner 版本至 v4。
* [2019-09-30] Lexus ISH 使用更精確的 EPS Steering Angle Sensor 
* [2019-09-27] 加入 Zorrobyte 的 curvature learner (https://github.com/zorrobyte/openpilot)
* [2019-09-27] 加入可開關駕駛監控的程式碼。
* [2019-09-27] 取消當 steering 出現錯誤時，自動切斷方向控制 2 秒的機制。
* [2019-09-27] 讓行車介面的「方向盤」/「轉彎」圖示半透明化。
* [2019-09-26] 修正當「啟用記錄服務」關閉時，make 會有問題的錯誤。 (感謝 shaoching885 和 afa 回報)
* [2019-09-24] 行車介面加入可開關的「前車」、「路線」、「車道」設定。
* [2019-09-24] 行車介面加入可開關的「方向燈號」提示。 (感謝 CloudJ 建議，程式碼來源: https://github.com/kegman/openpilot)
* [2019-09-23] 優化讀取 params 的次數。
* [2019-09-23] 加入可開關的車道偏移警示。
* [2019-09-23] 修正充電控制邏輯。
* [2019-09-23] 加入台灣 Prius 4.5 指紋。 (感謝 Lin Hsin Hung 提供)
* [2019-09-20] 加入充電控制功能。 (感謝 loveloveses 和 KT 建議)
* [2019-09-16] 加入台灣 CT200h 指紋。 (感謝 CloudJ 提供)
* [2019-09-16] 加入美版 CT200h 移植。 (感謝 thomaspich 提供)
* [2019-09-13] 行車介面加入可開關的「速度顯示」設定。
* [2019-09-09] 加入 GreyPanda 模式。
* [2019-08-28] 加入可調警示音量。
* [2019-08-27] 自動關機改為可調時長。

dragonpilot 0.6.3
========================
* [2019-10-11] 加入台灣版 2019 RAV4H 油電版指紋。
## 基于OpenCV3与GTK3+的车辆辅助驾驶系统
用于标准路面的偏移制导（带人物交通标志识别），可用于自动驾驶计算机视觉的入门学习和具体项目的二次开发  
克隆之前请确认好自己机子上面已经安装好下列库  
1. OpenCV 3.4.1  
2. libcurl  
3. ekho3.0  
4. caffe  
5. libvlc  
6. GTK3+  
7. tensorflow  
# 关于外设  
1. Emotiv脑电波耳机(可无外设)  
2. STM32/Arduino/MSP430  

#统一外设输出格式  
alpha:脑电波alpha波  
alpha:脑电波alpha波  
alpha:脑电波alpha波  
temperature:温度  
humidity::湿度  
GPS:GPS  
可选参数（三选一）  
speed:速度  
acc:加速度  
wheel:车轮转动次数  
```
{
	"alpha":alpha,
	"gama":gama,
	"beta":beta,
	"temperature":temperature,
	"humidity":humidity,
	"GPS":GPS,
	"speed":{
		"vx":vx,
		"vy":vy,
		"vz":vz	
	},
	"acc":{
		"ax":ax,
		"ay":ay,
		"az":az	
	},
	"wheel":{
		"1":cycle_1,
		"2":cycle_2,
		"3":cycle_3	
	}
	
}
```
### 开源协议[GPL](http://www.gnu.org/licenses/gpl-3.0.html)  
 
# 作者信息    
## Zhijia Tao
## QQ:2571440661
## 第二作者
## ZhenYu Ji
## QQ:804266219
## SiYu Yan
## QQ:2922528256

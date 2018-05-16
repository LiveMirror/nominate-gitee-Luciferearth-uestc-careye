## 基于OpenCV3与GTK3+的车辆辅助驾驶系统  
> 编译依赖   
> 1. OpenCV 3.4.1  
> 2. libcurl  
> 3. ekho3.0  
> 4. caffe  
> 5. libvlc  
> 6. GTK3+  
# 关于外设  
1. Emotiv脑电波耳机(可无外设)  
2. STM32/Arduino/MSP430  

#外设交互格式  
alpha:脑电波alpha波  
gama:脑电波gama波  
beta:脑电波beta波  
```
{
	"alpha":alpha,
	"gama":gama,
	"beta":beta,
}
```
* temperature:温度  
* humidity::湿度  
* GPS:GPS  

可选参数  

* speed:速度  
* ac:加速度  
* ga:角加速度  
* mf:磁场  
* gs:角速度  
* wheel:车轮转动次数  
```
{
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
[开源协议](http://www.gnu.org/licenses/gpl-3.0.html)  
 
> 作者信息    
> Zhijia Tao
> QQ:2571440661  
> 第二作者  
> ZhenYu Ji
> QQ:804266219  
> SiYu Yan
> QQ:2922528256

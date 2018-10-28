## SLAM自动控制系统  SLAM auto control system
> 编译依赖  build dependes 
> 1. OpenCV 3.4.2  
> 2. libcurl  
> 3. ekho3.0  
> 4. caffe  
> 5. libvlc  
> 6. GTK3+  
> 7. CUDA9.1(可选)  

# 关于外设  about dvice
1. STM32/Arduino/MSP430  
2. 思岚激光雷达 Slamtec rplidar A2
3. IMU惯性导航模块 JY901 IMU
4. Emotiv脑电波耳机(可选)  emotiv brain wave headset

#外设交互格式  
alpha:脑电波alpha波  brain wave alpha wave
gama:脑电波gama波  brain wave gama wave
beta:脑电波beta波  brain wave beta wave
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
* ac:加速度  acceleration
* ga:角加速度  angular acceleration
* mf:磁场  magnetic field
* gs:角速度  angular velocity
* wheel:车轮转动次数  wheel rotation times
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
	"ag":{
    		"agx":agx,
    		"agy":agy,
    		"agz":agz	
    	},
	"wheel":{
		"1":cycle_1,
		"2":cycle_2,
		"3":cycle_3	
	}
	
}
```
licenses  
[开源协议](http://www.gnu.org/licenses/gpl-3.0.html)  

*PS:脑电模块未开源*  
*PS:Brain wave mode is or core model and instable please wait our team dev open its code*
> Our Team    
> Zhijia Tao
> QQ:2571440661  
> ZhenYu Ji
> QQ:804266219  
> SiYu Yan
> QQ:2922528256  
> Atan
> QQ:1060579270

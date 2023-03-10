import cv2
import pyrealsense2
from realsense_depth import *

point = (400, 300)

def show_distance(event, x, y, args, params):
	global point
	point = (x, y)
def detect(color, des,xcor,ycor):
	if(des == 0):
		cv2.putText(color, ".", (xcor, ycor), cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 0), 2)
	elif(des < 1000):
		cv2.putText(color, ".", (xcor, ycor), cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 255), 2)	
	elif(des < 2000):
		cv2.putText(color, ".", (xcor, ycor), cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 255), 2)
	else:
		cv2.putText(color, ".", (xcor, ycor), cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 0), 2)
		
# Initialize Camera Intel Realsense
dc = DepthCamera()

# Create mouse event
cv2.namedWindow("Color frame")
cv2.setMouseCallback("Color frame", show_distance)

while True:
    
        
        j = 0
        i = 20
        ret, depth_frame, color_frame = dc.get_frame()
       	cv2.circle(color_frame,point,4,(0,0,255))
       	distance = depth_frame[point[1],point[0]]
       	cv2.putText(color_frame, "{}mm".format(distance), (point[0], point[1]-20), cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 255), 2)
        for j in range(24):
   
             
             b = depth_frame[20, i]
             detect(color_frame,b,i,20)
             
             c = depth_frame[40, i]
             detect(color_frame,c,i,40)
    
             d = depth_frame[60, i]
             detect(color_frame,d,i,60)
    
             e = depth_frame[80, i]
             detect(color_frame,e,i,80)
    
             f = depth_frame[100, i]
             detect(color_frame,f,i,100)
    
             g = depth_frame[120, i]
             detect(color_frame,g,i,120)
    
             H = depth_frame[140, i]
             detect(color_frame,H,i,140)
    
             a = depth_frame[160, i]
             detect(color_frame,a,i,160)
    
             j = depth_frame[180, i]
             detect(color_frame,j,i,180)
    
             k = depth_frame[200, i]
             detect(color_frame,k,i,200)
    
             m = depth_frame[220, i]
             detect(color_frame,m,i,220)
    
             n = depth_frame[240, i]
             detect(color_frame,n,i,240)
    
             o = depth_frame[260, i]
             detect(color_frame,o,i,260)
    
             p = depth_frame[280, i]
             detect(color_frame,p,i,280)
    
             q = depth_frame[300, i]
             detect(color_frame,q,i,300)
    
             r = depth_frame[320, i]
             detect(color_frame,r,i,320)
    
             s = depth_frame[340, i]
             detect(color_frame,s,i,340)
    
             t = depth_frame[360, i]
             detect(color_frame,t,i,360)
    
             u = depth_frame[380, i]
             detect(color_frame,u,i,380)
    
             v = depth_frame[400, i]
             detect(color_frame,v,i,400)
    
             w = depth_frame[420, i]
             detect(color_frame,w,i,420)
    
             x = depth_frame[440, i]
             detect(color_frame,x,i,400)
    
             y = depth_frame[460, i]
             detect(color_frame,y,i,460) 
          
   
             i = i+25
             cv2.imshow("Color frame", color_frame)
        key = cv2.waitKey(1)
        if key == 27:
             break
             
            
        

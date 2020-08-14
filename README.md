# raspistill.cgi
##### cgi interface for raspberrypi's raspistill
<br/><br/>
```
Usage:
  shutter=%d      Set shutter speed in microseconds
  ISO=%d          Set capture ISO
  flicker={...}   Set flicker avoid mode (see Notes)
  imxfx={...}     Set image effect (see Notes)
  width=%d        Set image width <size>
  height=%d       Set image height <size>
  drc={...}       Set DRC Level (see Notes)
  quality=%d      Set jpeg quality <0 to 100>


Notes:
  Flicker avoid mode options :
    off,auto,50hz,60hz

  Image Effect mode options :
    none,negative,solarise,sketch,denoise,emboss,oilpaint,hatch,gpen,pastel,watercolour,film,blur,saturation,colourswap,washedout,posterise,colourpoint,colourbalance,cartoon

  Dynamic Range Compression (DRC) options :
    off,low,med,high


Example:
  Use "raspistill.cgi?help" show this help
  Use "raspistill.cgi?width=1920&height=1080&quality=80" to set the image-width at 1920, image-height at 1080 and jpeg quality at 80 of 100
  Use "raspistill.cgi?shutter=10000&ISO=800" to set the shutter at 10000 micro seconds and ISO at 800
  ```

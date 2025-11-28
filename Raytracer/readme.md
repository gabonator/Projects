# Point cloud sphere finder

See it [live](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/Raytracer/raytracer.html)


```js
function analyse()
{
  const w = pointCloud[0].length;
  const h = pointCloud.length;
  let spheres = []
  for (let x=50; x<w-50; x+=20)
    for (let y=50; y<w-50; y+=20)
    {
      var pts = [];
      // moving window 3x3 points
      for (let _x=-1; _x<=1; _x++)
        for (let _y=-1; _y<=1; _y++)     
        {
          var found = 0;
          var avg = [0, 0, 0, 0, 0, 0]
          // filter out noise by averaging
          for (let fx=-2; fx<=2; fx++)
            for (let fy=-2; fy<=2; fy++)
            {
              let pt = pointCloud[y+_y*30+fy][x+_x*30+fx];
              if (pt)
              {
                found++
                for (let i=0; i<6; i++) 
                  avg[i] += pt[i];
              }
            }
          if (found)
          {
            for (let i=0; i<6; i++) 
              avg[i] /= found;
            for (let i=0; i<6; i++) 
              avg[i] = Math.floor(avg[i]*1000)/1000;
            pts.push(avg);
          }

          if (0)
          {
            var pt = pointCloud[y+_y*40][x+_x*40]
            if (pt)
              pts.push(pt);
          }
        }

      if (pts.length != 9)
        continue;

      for (let r=5; r<=7; r+=1)
      {
        let sum = [0, 0, 0];
        // sphere center = surface point - normalized normal * radius
        for (let i=0; i<pts.length; i++)
        {
          sum[0] += pts[i][0] - pts[i][3]*r;
          sum[1] += pts[i][1] - pts[i][4]*r;
          sum[2] += pts[i][2] - pts[i][5]*r;
        }
        // center
        sum = [sum[0]/pts.length, sum[1]/pts.length, sum[2]/pts.length]

        // error
        let err = [0, 0, 0]
        for (let i=0; i<pts.length; i++)
        {
          err[0] += Math.abs(pts[i][0] - pts[i][3]*r - sum[0])
          err[1] += Math.abs(pts[i][1] - pts[i][4]*r - sum[1])
          err[2] += Math.abs(pts[i][2] - pts[i][5]*r - sum[2])
        }
        var e = Math.sqrt(err[0]**2+err[1]**2+err[2]**2)

        // all projected centers close to each other?
        if (e < 0.3)
        {
          console.log("Stred gule", sum[0].toFixed(1), sum[1].toFixed(1), sum[2].toFixed(1), "r="+r, "err="+Math.floor(e*100)/100);
          if (!spheres.some(s=>(s[0]-sum[0])**2+(s[1]-sum[1])**2+(s[2]-sum[2])**2 < 5*5))
            spheres.push([...sum, r]);
        }
      }
    }
  return spheres;
}
```
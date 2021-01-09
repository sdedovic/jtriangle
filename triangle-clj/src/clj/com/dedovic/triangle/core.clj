(ns com.dedovic.triangle.core
  (:import  [com.dedovic.jtriangle.triangle JTriangle TriangulateIO]))

(defn triangulate
  "Given a sequence of points defining a polygon will return a lazy sequence of triangles
    from the result of triangulating the polygon."
  ([points] (triangulate points (count points)))
  ([points num-points]
   (let [pointArray (float-array (flatten points))
         in (new TriangulateIO)
         out (new TriangulateIO)
         vorout (new TriangulateIO)]
     (set! (.pointList in) pointArray)
     (set! (.numberOfPoints in) num-points)
     (JTriangle/triangulate "pczQ" in out vorout)
     (let [triangles (partition 3 (.triangleList out))
           triangles (map (fn [[idx-a idx-b idx-c]]
                            [(nth points idx-a)
                             (nth points idx-b)
                             (nth points idx-c)])
                          triangles)]
       triangles))))
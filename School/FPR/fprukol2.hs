data Point = Point Int Int deriving (Show, Eq)
data Line = Line Point Point deriving Show
data Triangle = Triangle Point Point Point deriving Show
type Result = [String]

pp :: Result -> IO ()
pp x = putStr (unlines x)

drawLines :: (Int, Int) -> [Line] -> Result
drawLines (columns, rows) lines =
  let grid = createGrid columns rows
      markGrid = foldl markLine grid lines
  in markGrid

drawTriangles :: (Int, Int) -> [Triangle] -> Result
drawTriangles (columns, rows) triangles =
  let linesForTriangles = concatMap triangleToLines triangles
  in drawLines (columns, rows) linesForTriangles

triangleToLines :: Triangle -> [Line]
triangleToLines (Triangle p1 p2 p3) = [Line p1 p2, Line p2 p3, Line p3 p1]

createGrid :: Int -> Int -> Result
createGrid columns rows = replicate rows (replicate columns '.')

markLine :: Result -> Line -> Result
markLine grid (Line (Point x1 y1) (Point x2 y2)) =
  let slope = if x1 == x2 then 0 else fromIntegral (y2 - y1) / fromIntegral (x2 - x1)
      points = if x1 == x2 then [(x1, y) | y <- [min y1 y2 .. max y1 y2]] else [(x, round (fromIntegral y1 + slope * fromIntegral (x - x1))) | x <- [min x1 x2 .. max x1 x2]]
  in foldl markPoint grid points

markPoint :: Result -> (Int, Int) -> Result
markPoint grid (x, y) =
  if 0 <= y && y < length grid && 0 <= x && x < length (head grid)
    then modifyElem grid y (\row -> modifyElem row x (const '#'))
    else grid

modifyElem :: [a] -> Int -> (a -> a) -> [a]
modifyElem list index f = take index list ++ [f (list !! index)] ++ drop (index + 1) list

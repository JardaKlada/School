type Crossword = [String]
type Result = [String]

crossword :: Crossword
crossword = ["...##....",
             ".#....##.",
             ".#.##....",
             "....#.#.#",
             "#.#...#.#",
             "#.#.#....",
             "....##.#.",
             ".##....#.",
             "....##.#."]

positions :: Result -> [(Int, Int)]
positions crossword = findPositions crossword 0 0

findPositions :: Result -> Int -> Int -> [(Int, Int)]
findPositions [] _ _ = []
findPositions (prvni:zbytek) radek sloupec =
  let positionsInRow = findPositionsInRow prvni radek sloupec
      positionsInRest = findPositions zbytek (radek + 1) sloupec
  in positionsInRow ++ positionsInRest

findPositionsInRow :: String -> Int -> Int -> [(Int, Int)]
findPositionsInRow [] _ _ = []
findPositionsInRow (_:[]) _ _ = []
findPositionsInRow (x:y:xs) radek sloupec =
  if x == '.' && y == '.'
    then (radek, sloupec) : findPositionsInRow (dropWhile(=='.') xs) radek (sloupec + (length(x:y:xs)-length(dropWhile(=='.') xs)))
    else findPositionsInRow (y:xs) radek (sloupec + 1)


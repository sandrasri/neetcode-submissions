class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        visited = set()
        currIsland = 0

        rows = len(grid)
        cols = len(grid[0])

        def explore_island(r, c):
            
            #check boundaries, if water or in visited
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == "0" or (r, c) in visited:
                return
            
            visited.add((r, c))

            explore_island(r-1, c) #Up 
            explore_island(r + 1, c) #Down
            explore_island(r, c - 1) #Left
            explore_island(r, c + 1) # Right
        
        for x in range(rows):
            for y in range(cols):
                if grid[x][y] == "1" and (x,y) not in visited:
                        currIsland += 1
                        explore_island(x, y)
        
        return currIsland
                        
                    
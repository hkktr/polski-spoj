// C++14 (gcc 8.3)
#include <iostream>
#include <string>
#include <vector>

void CheckMazeUtil(const std::vector<std::vector<char>>& maze,
                   std::vector<std::vector<char>>& visited, int x, int y) {
  if (x < 0 || x > maze.front().size() - 1) return;
  if (y < 0 || y > maze.size() - 1) return;
  if (maze[y][x] == 'X' || visited[y][x]) return;

  visited[y][x] = true;
  CheckMazeUtil(maze, visited, x - 1, y);
  CheckMazeUtil(maze, visited, x + 1, y);
  CheckMazeUtil(maze, visited, x, y - 1);
  CheckMazeUtil(maze, visited, x, y + 1);
}

bool CheckMaze(const std::vector<std::vector<char>>& maze, int start_x,
               int start_y, int end_x, int end_y) {
  std::vector<std::vector<char>> visited(
      maze.size(), std::vector<char>(maze.front().size(), false));
  CheckMazeUtil(maze, visited, start_x, start_y);
  return visited[end_y][end_x];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<std::vector<char>> maze(10, std::vector<char>(10));
  std::string maze_string;
  maze_string.reserve(100);

  while (std::cin >> maze_string) {
    int i{0};
    for (std::vector<char>& row : maze) {
      for (char& cell : row) {
        cell = maze_string[i];
        ++i;
      }
    }

    std::cout << CheckMaze(maze, 0, 0, 9, 9) << "\n";
  }

  return 0;
}
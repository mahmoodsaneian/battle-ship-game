```markdown
# Battleship Game

This project is a C language implementation of the classic Battleship game, where two players attempt to sink each other's fleet by guessing the locations of their opponent's ships.

## Features

- **Grid-Based Gameplay**: Players place their ships on a grid and take turns guessing the coordinates of enemy ships.
- **Single-Player Mode**: Play against a computer opponent with varying levels of difficulty.
- **Customizable Fleet**: Choose the number and types of ships to deploy.
- **Input Validation**: Ensures that player inputs are within the valid range and that ships do not overlap.

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/mahmoodsaneian/battle-ship-game.git
   cd battle-ship-game
   ```

2. **Compile the Code**:
   Ensure you have a C compiler installed on your system. Compile the `main.c` file using:
   ```bash
   gcc main.c -o battleship
   ```

3. **Run the Game**:
   ```bash
   ./battleship
   ```

## How to Play

1. **Setup**:
   - The game is played on a grid, typically 10x10.
   - Each player places a set of ships on their grid. Ships can be of varying lengths and must be placed either horizontally or vertically without overlapping.

2. **Gameplay**:
   - Players take turns calling out grid coordinates to attack.
   - The game indicates whether the attack is a hit or a miss.
   - The objective is to sink all of the opponent's ships before they sink yours.

3. **Winning the Game**:
   - The first player to sink all of the opponent's ships wins.

## Project Structure

```
battle-ship-game/
├── main.c
└── README.md
```

- `main.c`: Contains the main game logic and functions.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the classic Battleship board game.
- Developed as a project to practice C programming skills.

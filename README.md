# Chess-Engine-cpp
Designed and implemented a rule-complete chess engine in C++ using object-oriented principles, modeling board state, pieces, moves, and game flow. The engine supports legal move generation, check/checkmate detection, and game termination logic. A graphical interface built with raylib renders the chessboard and pieces, enabling interactive play through mouse input and dynamic visual updates.
<br>

<h2>♟️ Chess Project – Feature Overview</h2>

<table>
  <thead>
    <tr>
      <th align="left">Category</th>
      <th align="left">Feature</th>
      <th align="left">Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Core Architecture</td>
      <td>Object-Oriented Design</td>
      <td>Separate classes for Board, Piece, Move, move detection, and validity checking</td>
    </tr>
    <tr>
      <td>Core Architecture</td>
      <td>Modular Engine</td>
      <td>Clean separation between game logic and rendering layer</td>
    </tr>
    <tr>
      <td>Board &amp; State</td>
      <td>Board Representation</td>
      <td>8×8 board modeled using structured data types</td>
    </tr>
    <tr>
      <td>Board &amp; State</td>
      <td>Game State Management</td>
      <td>Maintains turn, active player, and game termination state</td>
    </tr>
    <tr>
      <td>Move Logic</td>
      <td>Legal Move Validation</td>
      <td>Ensures all moves follow official chess rules</td>
    </tr>
    <tr>
      <td>Move Logic</td>
      <td>Piece-Specific Movement</td>
      <td>Correct handling of pawn, rook, bishop, knight, queen, and king moves</td>
    </tr>
    <tr>
      <td>Move Logic</td>
      <td>Move Existence Check</td>
      <td>Detects whether any legal move exists for a given side</td>
    </tr>
    <tr>
      <td>Check System</td>
      <td>Check Detection</td>
      <td>Accurately detects when a king is under threat</td>
    </tr>
    <tr>
      <td>Check System</td>
      <td>Checkmate Detection</td>
      <td>Identifies checkmate using check state and move availability</td>
    </tr>
    <tr>
      <td>Gameplay Flow</td>
      <td>Turn-Based Control</td>
      <td>Alternates turns between White and Black</td>
    </tr>
    <tr>
      <td>Gameplay Flow</td>
      <td>Game End Handling</td>
      <td>Declares winner on checkmate and supports exit/resign states</td>
    </tr>
    <tr>
      <td>Graphical Interface</td>
      <td>Raylib Integration</td>
      <td>Uses raylib for window creation and rendering</td>
    </tr>
    <tr>
      <td>Graphical Interface</td>
      <td>Board Rendering</td>
      <td>Real-time graphical chessboard display</td>
    </tr>
    <tr>
      <td>Graphical Interface</td>
      <td>Piece Rendering</td>
      <td>Textured chess pieces rendered dynamically</td>
    </tr>
    <tr>
      <td>User Interaction</td>
      <td>Mouse-Based Input</td>
      <td>Click-to-select and click-to-move interaction model</td>
    </tr>
    <tr>
      <td>User Interaction</td>
      <td>Move Feedback</td>
      <td>Illegal moves are detected and rejected in real time</td>
    </tr>
    <tr>
      <td>Code Quality</td>
      <td>Readable &amp; Extensible</td>
      <td>Designed for easy extension (AI, move highlighting, online play)</td>
    </tr>
  </tbody>
</table>

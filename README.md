# TheHeroFramework
The Hero Framework is a modular ability and attribute system. It is a plug-in style architecture that could handle a character's health and special abilities like a dash or fireball.

# Core system

## 1. Attribute and state management
It has attribute component, which manages health- gain/lose. I added dynamic multicast deletage. this allows the UI and other gameplay system to listen for state changes only when they occur. significantly reducing CPU overhead.

## 2. Integration system
To handle world interactions (Door, Chest, power-ups/pickup) without expensive "Hard casting". I implemented a Interface system. Character performs a line trace (raycast) by pressing 'E' and if the hit actor implements IGameplayInterface, the code executes the interactoin logic. This allows the user to interact with different items with same C++ logic.

## 3. Data Asset
To reduce code duplication, I implemented a Primary Data Asset system. Using Enums and switch statements (useful for different type of powerup/task performance) a single C++ base class can perform different task.
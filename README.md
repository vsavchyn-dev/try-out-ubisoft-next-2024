# Try-out for Ubisoft Toronto Next 2024

This year's challenge was to make a game with "firing projectiles."

I was thinking about making a bullet hell genre game similar to [the Touhou Game series](https://en.wikipedia.org/wiki/Touhou_Project), but I had several problems:

- Lack of math skills (specifically 3D math)
- Lack of time (I started EXTREMELY late)

I only had time to finish Vector and Matrix classes, which I would've used for all manipulation in Scene and Camera. Also, I planned to use a pool allocator as it's much more efficient than standard malloc and new for a large number of objects (bullets, particles, and all of the triangles). Chaining this with proper ECS = performant and expansible game! But not this time, unfortunately.

Even though I was not able to finish it on time, this work will serve as a great experience for future personal projects and a reminder that I can do better.

## How to run a scene with a rotating cube

Unfortunately, the current Scene class has bugs. It will be fixed soon, I promise! Until then:

- Pull repository
- Open Game.sln file on Visual Studio (preferably 2022 version)
- Hit F5 and get an error!
- Wait for the fix!

This "game" was originally designed for Windows machines, so you can't run it on Unix machines :(

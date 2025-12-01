---
description: Add a new example source file under the topic folder, update the top-level `list.md` index, and update the `TOPICS.md` index file. Add time and space complexity to the new example file and to `Complexities.md`.
arguments:
  - name: topic
    description: The topic folder (e.g. '4. Trees') where the new example should be added.
    required: true

Behavior:
- Place the code as a single self-contained source file inside the topic folder.
- Add the time complexity and space complexity as comments at the top of the new example file as well as on `Complexities.md` file in the root.
- Add a bullet for the new example under the same topic in the repo root `list.md`.
- Add a bullet for the new example under the same topic in the repo root `TOPICS.md`.

## User Input

```text
$ARGUMENTS


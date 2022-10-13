# solve1.sql

Runtime 621 ms

Beats 34.85%

A bit of strange ...

# If console is broken to run test

https://www.db-fiddle.com/

```
CREATE TABLE Tree (
  `id` INT,
  `p_id` INT
);

INSERT INTO Tree
  (`id`, `p_id`)
VALUES
  (1, NULL),
  (2, 1),
  (3, 1),
  (4, 2),
  (5, 2);
```

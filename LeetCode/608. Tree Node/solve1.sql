# Write your MySQL query statement below
SELECT id , 'Root' as type
FROM Tree
WHERE p_id IS NULL

UNION 

SELECT id, 'Inner' as type
FROM Tree
WHERE id IN (SELECT DISTINCT p_id AS id FROM Tree) AND (p_id IS NOT NULL)
    
UNION

SELECT id, 'Leaf' as type
FROM Tree
WHERE id NOT IN (SELECT DISTINCT p_id AS id FROM Tree WHERE p_id IS NOT NULL) AND (p_id IS NOT NULL)

ORDER BY id;

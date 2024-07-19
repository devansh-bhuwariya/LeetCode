# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE id%2!=0 and description NOT IN ("Boring")
ORDER BY rating DESC;
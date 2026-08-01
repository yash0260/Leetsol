# Write your MySQL query statement below
SELECT e.name
FROM Employee e
JOIN Employee t
ON e.id = t.managerId
GROUP BY e.id
HAVING COUNT(*) >= 5;
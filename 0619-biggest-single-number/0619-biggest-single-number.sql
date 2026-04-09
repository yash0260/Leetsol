# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM( SELECT num
FROM Mynumbers
group by num
having count(*)=1
)AS temp;
-- SELECT MAX(num) FROM temp;
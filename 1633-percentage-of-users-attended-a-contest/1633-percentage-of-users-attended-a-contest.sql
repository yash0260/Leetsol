# Write your MySQL query statement below
SELECT contest_id,
ROUND(
IFNULL(COUNT(contest_id) *100.0 / (SELECT COUNT(*) FROM Users), 0),
        2
    ) AS percentage
FROM Users u
LEFT JOIN Register r 
ON u.user_id=r.user_id
where r.contest_id IS NOT NULL
GROUP BY r.contest_id ORDER BY percentage DESC,contest_id ASC;
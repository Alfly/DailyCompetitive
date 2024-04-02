## 用一条 SQL 语句查询出每门课都大于 80 分的学生姓名

### 建表及插入数据
```sql
DROP TABLE IF EXISTS student;
CREATE TABLE student (
    id int NOT NULL primary key AUTO_INCREMENT,
    score double NOT NULL,
    name varchar(50) DEFAULT NULL,
    course varchar(50) DEFAULT NULL,
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

---
INSERT INTO student VALUES ('1', '80', 'elf', 'english');
```

### 查询

使用 having

```sql
SELECT name
FROM student
GROUP BY name
Having Min(score) >= 80;
```

逆向思维：先查出有课程成绩小于80分的学生姓名，然后用 not in 或 not exists 进行排除

- NOT IN
```sql
SELECT DISTINCT name
FROM student a
WHERE name NOT IN (
    SELECT DISTINCT name FROM student b WHERE score < 80
);
```

- NOT EXISTS

```sql
SELECT DISTINCT a.name
FROM student a
WHERE NOT EXISTS (
    SELECT 1 FROM student b WHERE b.score < 80 AND b.name = a.name
);
```
### 常见 git 命令

**通常我们使用以下三条命令进行上传代码**

- git add filename  // 添加文件
- git commit -m "注释"  // 添加注释
- git push  // 推送至远程仓库

**配置用户名和密码**

- git config --global user.name
- git config --global user.email

**合并分支、切换分支、删除分支**

- git checkout master   // 切换分支
- git branch -d master  // 删除本地分支
- git push origin --delete master // 删除远程分治
- git branch --merged // 合并分支

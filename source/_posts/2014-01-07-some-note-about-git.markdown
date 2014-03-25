---
layout: post
title: "Git的一些笔记"
date: 2014-01-07 01:17:46 +0800
comments: true
categories: 
---



添加远程仓库，用alias代称
```
$ git remote add alias git@github.com:username/repo_name.git
```

删除某个仓库代称
```
$ git remote rm alias
```


提交本地代码到远程仓库
```
$ git push alias branch
```
alias代入远程仓库代称，branch代入仓库代码分支


git在push的时候，如果仓库的地址写的是"https://..."则需要输入用户名和密码，在Arch上我发现怎么输入正确的用户名和密码都会显示username/password错误，原因不明。

修改仓库设置
```
$ emacs git .git/config
```
我将repo的地址改为git@github.com:username/repo_name.git之后，配置sshkey方式的认证，就不需要输入用户名和密码，且能成功提交。

下面是sshkey的配置方式：
```
$ cd ~/.ssh
$ ssh-genkey -t rsa -C "my_email@gmail.com"
$ ssh-add id_rsa
$ emacs id_rsa.pub
# C-x C-h M-w 复制，然后到github个人profile页面添加sshkey，完成
```

EOF
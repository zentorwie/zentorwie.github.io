---
layout: post
title: "解决由于GoogleFont被墙导致的博客载入缓慢"
date: 2014-11-06 21:14:33 +0800
comments: true
categories: web
---

本博客用了Google的在线字体，由于众所周知的原因，Google服务在大陆不能正常访问，这就导致了使用了GoogleAPI包括Google字体服务的网站在大陆打开十分龟速。为了解决这个问题，一个解决方案是不要使用这些服务，另外一个方案使用Google这些服务在墙内的镜像，比如可以使用中国科学技术大学LUG提供的代理，参见[这里](https://servers.ustclug.org/2014/06/blog-googlefonts-speedup/)。

为了解决这个问题，我查到了批量文本替换的[办法](http://blog.csdn.net/kauu/article/details/1757325)。

于是自己写了一个笨笨的脚本：
```
sed -i "s/ajax.googleapis.com/ajax.lug.ustc.edu.cn/g" `grep ajax.googleapis.com -rl zentorwie.github.io`
sed -i "s/fonts.googleapis.com/fonts.lug.ustc.edu.cn/g" `grep fonts.googleapis.com -rl zentorwie.github.io`
sed -i "s/themes.googleusercontent.com/google-themes.lug.ustc.edu.cn/g" `grep themes.googleusercontent.com -rl zentorwie.github.io`
```
如果你想用这个脚本，先要把zentorwie.github.io这个目录（也就是我放Octopress博客的目录）改成你自己要批量修改的目录，然后在这个目录的上一级目录执行（防止脚本自己也被修改了）。

批量修改完，重新部署博客就OK了。

感谢USTCLUG！

EOF



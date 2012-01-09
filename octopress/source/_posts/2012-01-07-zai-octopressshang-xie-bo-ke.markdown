---
layout: post
title: "在octopress上写博客"
date: 2012-01-07 22:23
comments: true
categories: Web 
---
<p>在github上捣鼓了一阵后，决定把博客建在<a href="http://octopress.org/" title="octopress">octopress</a>上，    相对于<a href="wordpress.org" title="wordpress">wordpress</a>，octopress的优点在于：</p>

<blockquote>
  <ul>
<li>octopress的大小只有1.4M，对于博客的部署，相对方便。</li>
<li>支持<a href="http://daringfireball.net/projects/markdown" title="Markdown">Markdown</a>语法。</li>
<li>使用静态页面，速度更快。</li>
</ul>
</blockquote>

<h2>Markdown简介</h2>

<p>Markdown可以方便的将文本内容转换成网页，通过相对简单的语法，可以实现很丰富的网页内容。</p>

<h2>建立新的日志</h2>

<p>orcopress博客的日志默认被存在<code>source/_posts</code>文件夹中，并且根据Jekyll的命名规则命名为<code>YYYY-MM-DD-post-title.markdown</code>这种格式。</p>

<h3>生成新的日志</h3>

<pre><code>rake new_post["title"]
rake generate 
rake watch
rake preview
</code></pre>

<h3>提交到github中</h3>

<pre><code>rake deploy
git add .
git commit -m 'commit'
git push origin source</code></pre>

<h2>代码插件</h2>

orcopress可以使用代码插件在日志中显示相关的代码。
####实例如下:
{%codeblock C语言测试 hello.c lang:c%}
include <stdio.h>
int main()
{
    printf("hello world");
    return 0;
}
{%endcodeblock%}

####使用include_code显示代码文件
下面例子显示的内容来自<code>source/downloads/code/test.js</code>文件中。
{% include_code test.js %}


####使用Gist显示代码
[Gist](https://gist.github.com/)是托管在github上的用于显示代码的项目。octopress可以通过Gist Tag来显示代码。

实例如下：
{% gist 1575067 %}

##HTML5 视频插件
通过视频插件可以播放HTML5视频

####实例如下:
{% video http://s3.imathis.com/video/zero-to-fancy-buttons.mp4 640 320 http://s3.imathis.com/video/zero-to-fancy-buttons.png %}

##显示图片
ortopress的图片显示和Markdown语法类似

####实例如下：
{% img http://placekitten.com/890/280 %}
{% img left http://placekitten.com/320/250 Place Kitten #2 %}
{% img right http://placekitten.com/300/500 150 250 Place Kitten #3 %}
{% img right http://placekitten.com/300/500 150 250 'Place Kitten #4' 'An image of a very cute kitten' %}

